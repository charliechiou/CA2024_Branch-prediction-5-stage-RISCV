import argparse
import os


def little_to_big_endian(data, word_size=4):
    """
    Convert Little Endian data to Big Endian.

    Args:
        data (bytes): The input binary data in Little Endian format.
        word_size (int): The size of each word in bytes (default: 4 bytes).

    Returns:
        bytes: The converted Big Endian data.
    """
    if len(data) % word_size != 0:
        raise ValueError(f"Data length ({len(data)}) is not aligned with word size ({word_size}).")

    big_endian_data = bytearray()
    for i in range(0, len(data), word_size):
        little_endian_word = data[i:i + word_size]
        big_endian_word = little_endian_word[::-1]  # Reverse the bytes
        big_endian_data.extend(big_endian_word)

    return bytes(big_endian_data)


def convert_file(input_file, output_file, word_size=4):
    """
    Convert a binary file from Little Endian to Big Endian.

    Args:
        input_file (str): Path to the input binary file.
        output_file (str): Path to save the converted Big Endian file.
        word_size (int): The size of each word in bytes (default: 4 bytes).
    """
    with open(input_file, "rb") as infile:
        data = infile.read()

    big_endian_data = little_to_big_endian(data, word_size)

    with open(output_file, "wb") as outfile:
        outfile.write(big_endian_data)
    print(f"Converted {input_file} to Big Endian and saved as {output_file}.")


def main():
    parser = argparse.ArgumentParser(description="Convert Little Endian binary to Big Endian.")
    parser.add_argument("input", help="Input binary file")
    parser.add_argument("output", help="Output file path")
    parser.add_argument("--word-size", type=int, default=4, help="Word size in bytes (default: 4)")
    args = parser.parse_args()

    convert_file(args.input, args.output, args.word_size)


if __name__ == "__main__":
    main()
