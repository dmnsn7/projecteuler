#!/usr/bin/env python3
import sys

m = {}


def dfs(n, last, flag):
    if n == 1:
        return 1 if last != 0 else 0
    if (n, last, flag) in m.keys():
        return m[(n, last, flag)]
    ans = 0
    if flag == 1:
        for i in range(0, last + 1):
            ans += dfs(n - 1, i, flag)
    else:
        for i in range(last, 10):
            ans += dfs(n - 1, i, flag)
    m[(n, last, flag)] = ans
    return ans


def main():
    ans = 0
    for i in range(1, 101):
        for j in range(0, 10):
            ans += dfs(i, j, 1) + dfs(i, j, -1)
        ans -= 9
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
