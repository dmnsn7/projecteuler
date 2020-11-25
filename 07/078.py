#!/usr/bin/env python3
import sys


def get_pentagon(n):
    ret = []
    for i in range(0, n):
        pentagon = 0
        if i % 2 == 0:
            pentagon = (i // 2 + 1) * (i // 2 * 3 + 3 - 1) // 2
        else:
            pentagon = (-(i // 2) - 1) * (-(i // 2) * 3 - 3 - 1) // 2
        ret.append(pentagon)

    return ret


N = 100001
P = get_pentagon(N)
DP = [0] * N


def dfs(n):
    if n <= 1:
        return 1
    if DP[n] != 0:
        return DP[n]
    ans = 0
    for i, num in enumerate(P):
        if num > n:
            break
        if i % 4 < 2:
            ans += dfs(n - num)
        else:
            ans -= dfs(n - num)
    DP[n] = ans

    return ans


def main():
    for i in range(0, N):
        if dfs(i) % 1000000 == 0:
            print(i)
            break


if __name__ == "__main__":
    sys.exit(main())
