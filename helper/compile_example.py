#!/usr/bin/python3
import argparse
from glob import glob
import os
import sys


parser = argparse.ArgumentParser(description="Process some integers.")
parser.add_argument("example", metavar="01", type=int, nargs="?",
                    help="integer representing the example number")


def get_available_examples() -> list:
    examples_path = glob("../examples/*_*.c", recursive=False)
    examples = [os.path.basename(example) for example in examples_path]
    print(f"Examples available: {len(examples)}")
    return examples


if __name__ == "__main__":
    print("Kernel module compiler called!")
    args = parser.parse_args()
    if not args.example:
        print("Insert the example number.")
        sys.exit(0)

    get_available_examples()
