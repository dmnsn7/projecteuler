#!/usr/bin/env python3
import sys


def main():
    ans = 0
    for i in range(2, 100):
        if int(i**0.5)**2 == i:
            continue
        l, r = 0, 10**100
        while l + 1 != r:
            m = (l + r) // 2
            if m * m <= 10**198 * i:
                l = m
            else:
                r = m
        while l:
            ans += l % 10
            l //= 10
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
