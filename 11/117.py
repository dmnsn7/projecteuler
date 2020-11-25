#!/usr/bin/env python3
import sys

dp = {}


def dfs(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n in dp.keys():
        return dp[n]
    dp[n] = dfs(n - 1) + dfs(n - 2) + dfs(n - 3) + dfs(n - 4)
    return dp[n]


def main():
    print(dfs(50))


if __name__ == "__main__":
    sys.exit(main())
