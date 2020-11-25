#!/usr/bin/env python3
import sys


def prime_sieve(n):
    pri, phi = [], list(range(n))
    for i in range(2, n):
        if phi[i] == i:
            phi[i] = i - 1
            pri.append(i)
        for x in pri:
            ti, multi = x * i, 1
            if ti >= n:
                break
            while ti % x == 0:
                ti //= x
                multi *= x
            phi[x * i] = phi[ti] * multi * (x - 1) // x
            if i % x == 0:
                break
    return pri, phi


def pow_mod(a, b, c):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % c
        b >>= 1
        a = a * a % c
    return ans % c


def main():
    pri, phi = prime_sieve(1100000)
    ans = 0
    for p in pri:
        if p > 100000:
            break
        x = pow_mod(10, p, phi[9 * p])
        x = pow_mod(10, x, 9 * p)
        if x != 1:
            ans += p
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
