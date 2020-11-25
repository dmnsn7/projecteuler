#!/usr/bin/env python3
import sys

cur = [1]
dp = {}


def dfs():
    if len(cur) > 12:
        return
    dp[cur[-1]] = len(cur) - 1 if cur[-1] not in dp.keys() else min(
        dp[cur[-1]],
        len(cur) - 1)
    used = {}
    for x in cur:
        for y in cur:
            if x + y > cur[-1] and x + y < 201 and x + y not in used.keys():
                if x + y in dp.keys() and dp[x + y] < len(cur):
                    continue
                used[x + y] = 1
                cur.append(x + y)
                dfs()
                cur.pop()


def main():
    dfs()
    print(sum(dp.values()))


if __name__ == "__main__":
    sys.exit(main())
