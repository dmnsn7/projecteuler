#!/usr/bin/env python3
import sys


def main():
    N, a, b = 100, 1, 2

    for i in range(0, N - 1):
        c = 1 if i % 3 != 1 else (i // 3 + 1) * 2
        a = a + b * c
        a, b = b, a
    add_up = 0
    while b:
        add_up += b % 10
        b //= 10
    print(add_up)


if __name__ == "__main__":
    sys.exit(main())
