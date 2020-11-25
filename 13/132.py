#!/usr/bin/env python3
import sys


def prime_sieve(n):
    pri, isp = [], [1] * n
    for i in range(2, n):
        if isp[i]:
            pri.append(i)
        for x in pri:
            if i * x >= n:
                break
            isp[i * x] = 0
            if i % x == 0:
                break
    return pri


def pow_mod(a, b, c):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % c
        b >>= 1
        a = a * a % c
    return ans % c


def main():
    pri = prime_sieve(200000)
    cnt, ans = 0, 0
    for p in pri:
        if pow_mod(10, 10**9, 9 * p) == 1:
            ans += p
            cnt += 1
            if cnt == 40:
                break
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
