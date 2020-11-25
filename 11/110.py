#!/usr/bin/env python3
import sys

prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
m = {i: 0 for i in range(0, 15)}


def dfs(cur_multiply, cur_idx, cur_ans):
    ways = 1
    for i in m:
        ways *= m[i] * 2 + 1
    ways = (ways + 1) / 2
    if ways > 4000000:
        cur_ans = min(cur_ans, cur_multiply)
    for idx in range(cur_idx, len(prime)):
        if cur_multiply * prime[idx] > cur_ans:
            break
        if idx >= 1 and m[idx] >= m[idx - 1]:
            continue
        m[idx] = 1 if idx not in m.keys() else m[idx] + 1
        cur_ans = min(cur_ans, dfs(cur_multiply * prime[idx], idx, cur_ans))
        m[idx] = m[idx] - 1
    return cur_ans


def main():
    print("{}".format(dfs(1, 0, 10**20)))


if __name__ == "__main__":
    sys.exit(main())
