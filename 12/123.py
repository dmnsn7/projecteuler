#!/usr/bin/env python3
import sys


def prime_sieve(n):
    prime = []
    is_prime = [1] * n
    for i in range(2, n):
        if is_prime[i]:
            prime.append(i)
        for p in prime:
            if (p * i >= n):
                break
            is_prime[p * i] = 0
            if (i % p == 0):
                break
    return prime


def pow_mod(a, b, c):
    ans = 1
    while b:
        if b % 2 == 1:
            ans = ans * a % c
        b //= 2
        a = a * a % c
    return ans % c


def main():
    primes = prime_sieve(1000000)
    for i, p in enumerate(primes):
        r = (pow_mod(p - 1, i + 1, p * p) +
             pow_mod(p + 1, i + 1, p * p)) % (p * p)
        if r > 10**10:
            print(i + 1)
            break


if __name__ == "__main__":
    sys.exit(main())
