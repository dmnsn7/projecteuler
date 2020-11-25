#!/usr/bin/env python3
import sys


def prime_sieve(n):
    prime, is_prime = [], [1] * n
    for i in range(2, n):
        if is_prime[i]:
            prime.append(i)
        for j in prime:
            if j * i >= n:
                break
            is_prime[i * j] = 0
            if i % j == 0:
                break
    return is_prime


def main():
    ans, is_prime = 0, prime_sieve(1000000)
    for i in range(2, 600):
        for j in range(1, i):
            if i**3 - j**3 < 1000000 and is_prime[i**3 - j**3]:
                ans += 1
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
