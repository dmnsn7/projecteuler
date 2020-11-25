#!/usr/bin/env python3
import sys


def main():
    ans = 0
    for i in range(1, 500001):
        add = (int((i * i + 1000000)**0.5) - i) // 2
        ans += add
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
