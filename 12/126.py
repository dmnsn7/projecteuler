#!/usr/bin/env python3
import sys


def main():
    d = {}
    for a in range(1, 100):
        for b in range(a, 100):
            for c in range(b, 10000):
                X, Y, Z = 2 * (a * b + a * c + b * c), 2 * (
                    a * b + a * c + b * c) + 4 * (a + b + c), 2 * (
                        a * b + a * c + b * c) + 8 * (a + b + c) + 8
                if X >= 20000:
                    break
                while X < 20000:
                    d[X] = 1 if not X in d.keys() else d[X] + 1
                    X, Y, Z = Y, Z, 3 * Z - 3 * Y + X
    for i in range(20000):
        if i in d.keys() and d[i] == 1000:
            print(i)
            break


if __name__ == "__main__":
    sys.exit(main())
