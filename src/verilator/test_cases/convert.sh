#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_file.s>"
    exit 1
fi

INPUT_S=$1

BASENAME=$(basename "$INPUT_S" .s)

OBJ_FILE="${BASENAME}.o"
OUT_FILE="${BASENAME}.out"
BIN_FILE="${BASENAME}.bin"
BIG_ENDIAN_FILE="${BASENAME}_big_endian.bin"

riscv32-unknown-linux-gnu-as -o "$OBJ_FILE" "$INPUT_S"
if [ $? -ne 0 ]; then
    echo "Assembly failed for $INPUT_S"
    exit 1
fi

riscv32-unknown-linux-gnu-ld -o "$OUT_FILE" "$OBJ_FILE"
if [ $? -ne 0 ]; then
    echo "Linking failed for $OBJ_FILE"
    exit 1
fi

riscv32-unknown-linux-gnu-objcopy -O binary "$OUT_FILE" "$BIN_FILE"
if [ $? -ne 0 ]; then
    echo "Objcopy failed for $OUT_FILE"
    exit 1
fi

python3 convert.py "$BIN_FILE" "$BIG_ENDIAN_FILE"
if [ $? -ne 0 ]; then
    echo "Endian conversion failed for $BIN_FILE"
    exit 1
fi

echo "Successfully converted $INPUT_S to Big Endian binary: $BIG_ENDIAN_FILE"
xxd -g 4 -c 4 -p $BIG_ENDIAN_FILE > "${BASENAME}.hex"
riscv32-unknown-linux-gnu-objdump -D "$OBJ_FILE" > "${BASENAME}.dump"
rm *.bin *.o *.out