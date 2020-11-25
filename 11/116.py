#!/usr/bin/env python3
import sys

dp = {}


def dfs(n, m):
    if n < m:
        return 1
    if (n, m) in dp.keys():
        return dp[(n, m)]
    dp[(n, m)] = dfs(n - 1, m) + dfs(n - m, m)
    return dp[(n, m)]


def main():
    ans = 0
    for i in range(2, 5):
        ans += dfs(50, i)
    print(ans - 3)


if __name__ == "__main__":
    sys.exit(main())
