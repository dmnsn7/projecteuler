#!/usr/bin/env python3
import sys


def main():
    ans = 0
    v = [sum([(-i)**j for j in range(0, 11)]) for i in range(1, 11)]
    for i in range(1, 11):
        tv = v[0:i]
        while (len(tv) > 1):
            ans += tv[-1]
            tv = [tv[i + 1] - tv[i] for i in range(0, len(tv) - 1)]
        ans += tv[-1]
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
