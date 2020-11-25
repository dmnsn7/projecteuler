#!/usr/bin/env python3
import sys


def ok(n):
    return ''.join(sorted(n)) == '123456789'


def multiply(a, b):
    return [
        a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3],
        a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]
    ]


def pow_mod(a, t):
    ans = [1, 0, 0, 1]
    while t:
        if t % 2 == 1:
            ans = multiply(ans, a)
        t //= 2
        a = multiply(a, a)
    return ans


def main():
    x, y, idx = 1, 1, 3
    while True:
        x, y = y, (x + y) % 1000000000
        if ok(str(y)):
            mat = pow_mod([0, 1, 1, 1], idx)
            if (ok(str(mat[1])[0:9])):
                print(idx)
                break
        idx += 1


if __name__ == "__main__":
    sys.exit(main())
