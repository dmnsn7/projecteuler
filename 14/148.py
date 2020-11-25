#!/usr/bin/env python3
import sys


def dfs(n):
    if n <= 7:
        return n * (n + 1) // 2
    tn, m = n, 1
    while tn > 7:
        tn //= 7
        m *= 7
    return dfs(m) * (1 + tn) * tn // 2 + (tn + 1) * dfs(n % m)


def main():
    print(dfs(10**9))


if __name__ == "__main__":
    sys.exit(main())
