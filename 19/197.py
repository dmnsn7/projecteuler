#!/usr/bin/env python3
import sys


def main():
    x, ans = 1.0, 0
    for _ in range(1000):
        x = int(2**(30.403243784 - x**2) + 10**-9) / 10**9
        ans = x + int(2**(30.403243784 - x**2) + 10**-9) / 10**9
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
