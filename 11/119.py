#!/usr/bin/env python3
import sys


def main():
    v = []
    for i in range(2, 30 * 9):
        for j in range(2, 100):
            if i**j < 10:
                continue
            if i**j >= 10**30:
                break
            bits, num = 0, i**j
            while num:
                bits += num % 10
                num //= 10
            if bits == i:
                v.append(i**j)
    v = sorted(v)
    print(v[29])


if __name__ == "__main__":
    sys.exit(main())
