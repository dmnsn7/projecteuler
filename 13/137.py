#!/usr/bin/env python3
import sys


def main():
    '''
    x(n) = ((5 * n * n + 2 * n + 1)**0.5 - (n + 1)) / (2 * n)
    5 * n * n + 2 * n + 1 = d * d
    X * X - 5 * Y * Y = -4
    X, Y = [(1, 1), (4, 2), (11, 5)]
    T = ((3 / 2, 5 / 2), (1 / 2, 3 / 2))
    '''
    a, b, cnt = 1, 1, 0
    for _ in range(0, 40):
        a, b = (5 * b + 3 * a) // 2, (3 * b + a) // 2
        if a % 5 == 1:
            cnt += 1
            if cnt == 15:
                print((a - 1) // 5)


if __name__ == "__main__":
    sys.exit(main())
