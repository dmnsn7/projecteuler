#!/usr/bin/env python3
import sys


def main():
    a, b, ans = 38, 17, 0
    for _ in range(12):
        ans += b
        a, b = a * 9 + b * 20, a * 4 + b * 9
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
