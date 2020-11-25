#!/usr/bin/env python3
import sys


def prime_sieve(n):
    prime, phi = [], list(range(0, n))
    for i in range(2, n):
        if phi[i] == i:
            phi[i] = i - 1
            prime.append(i)
        for x in prime:
            ti, multi = x * i, 1
            if ti >= n:
                break
            while ti % x == 0:
                ti //= x
                multi *= x
            phi[x * i] = phi[ti] * multi * (x - 1) // x
            if i % x == 0:
                break
    return phi


def pow_mod(a, b, c):
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % c
        b >>= 1
        a = a * a % c
    return ans % c


def get_ans(n, r):
    d = []
    for i in range(2, n):
        if i >= n // i:
            break
        if n % i == 0:
            d.append(n // i)
        if n % i == 0 and pow_mod(10, i, r) == 1:
            return i
    for i in d[::-1]:
        if pow_mod(10, i, r) == 1:
            return i
    return 0


def main():
    phi = prime_sieve(1100000)
    for i in range(1000000, 1100000):
        if i % 2 == 0 or i % 5 == 0:
            continue
        p = 6 * phi[i] if i % 3 == 0 else 9 * phi[i]
        if get_ans(p, 9 * i) > 1000000:
            print(i)
            break


if __name__ == "__main__":
    sys.exit(main())
