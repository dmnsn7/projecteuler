#!/usr/bin/env python3
import sys


def prime_sieve(n):
    prime, fac_num = [], [1] * n
    for i in range(2, n):
        if fac_num[i] == 1:
            fac_num[i] = 2
            prime.append(i)
        for x in prime:
            ti, multi = x * i, 1
            if ti >= n:
                break
            while ti % x == 0:
                ti //= x
                multi += 1
            fac_num[x * i] = fac_num[ti] * multi
            if i % x == 0:
                break
    return fac_num


def main():
    fac_num = prime_sieve(10**7 + 1)
    ans = 0
    for i in range(2, 10**7):
        if fac_num[i] == fac_num[i + 1]:
            ans += 1
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
