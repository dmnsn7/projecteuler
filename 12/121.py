#!/usr/bin/env python3
import sys
import math


def main():
    ok, total = 0, math.factorial(16)
    for i in range(0, 2**15):
        bits, multiply = 0, 1
        for j in range(0, 15):
            if i & (1 << j):
                bits += 1
            else:
                multiply *= j + 1
        if bits > 15 - bits:
            ok += multiply
    print(total // ok)


if __name__ == "__main__":
    sys.exit(main())
