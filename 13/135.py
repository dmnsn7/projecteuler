#!/usr/bin/env python3
import sys


def main():
    f = [[] for _ in range(0, 10**6)]
    for i in range(1, 10**6):
        for j in range(i, 10**6, i):
            f[j].append(i)
    ans = 0
    for i in range(1, 10**6):
        cnt = 0
        for x in f[i]:
            if (x * x + i) % (4 * x) == 0 and x > (x * x + i) // (4 * x):
                cnt += 1
        ans += 1 if cnt == 10 else 0
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
