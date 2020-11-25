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
    dp[n] = dfs(n - 1)
    for i in range(3, n):
        dp[n] += dfs(n - i - 1)
    if n >= 3:
        dp[n] += 1
    return dp[n]


def main():
    print(dfs(50))


if __name__ == "__main__":
    sys.exit(main())
