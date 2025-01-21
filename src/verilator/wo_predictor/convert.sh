#!/bin/bash

# 檢查參數
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_file.s>"
    exit 1
fi

# 輸入的 .s 文件
INPUT_S=$1

# 提取文件名（不帶擴展名）
BASENAME=$(basename "$INPUT_S" .s)

# 中間文件與最終輸出文件
OBJ_FILE="${BASENAME}.o"
OUT_FILE="${BASENAME}.out"
BIN_FILE="${BASENAME}.bin"
BIG_ENDIAN_FILE="${BASENAME}_big_endian.bin"

# 組譯 .s 文件為目標文件
riscv32-unknown-linux-gnu-as -o "$OBJ_FILE" "$INPUT_S"
if [ $? -ne 0 ]; then
    echo "Assembly failed for $INPUT_S"
    exit 1
fi

# 生成可執行文件
riscv32-unknown-linux-gnu-ld -o "$OUT_FILE" "$OBJ_FILE"
if [ $? -ne 0 ]; then
    echo "Linking failed for $OBJ_FILE"
    exit 1
fi

# 轉換為二進制文件
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
xxd -g 4 -c 4 -p $BIG_ENDIAN_FILE > output.hex