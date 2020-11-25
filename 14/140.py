#!/usr/bin/env python3
import sys


def main():
    '''
    x(n) = ((5 * n * n + 14 * n + 1)**0.5 - (n + 1)) / (2 * (n + 3))
    5 * n * n + 14 * n + 1 = d * d
    X * X - 5 * Y * Y = 44
    X, Y = [(7, 1, 8, 2), (13, 5, 17, 7), (32, 14, 43, 19)]
    T = ((3 / 2, 5 / 2), (1 / 2, 3 / 2))
    '''
    a, b, c, d, cnt, ans = 7, 1, 8, 2, 0, 0
    for _ in range(0, 40):
        a, b = (5 * b + 3 * a) // 2, (3 * b + a) // 2
        c, d = (5 * d + 3 * c) // 2, (3 * d + c) // 2
        if a % 5 == 2:
            cnt += 1
            ans += (a - 7) // 5
            if cnt == 30:
                break
        if c % 5 == 2:
            cnt += 1
            ans += (c - 7) // 5
            if cnt == 30:
                break
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
