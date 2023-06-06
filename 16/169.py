#!/usr/bin/env python3
import sys

G = {0: 0, 1: 1}
H = {0: 1, 1: 0}


def g(n):
    if G.get(n) is not None:
        return G[n]
    G[n] = h(n - 2) if n % 2 == 0 else g(n // 2) + h(n // 2)
    return G[n]


def h(n):
    if H.get(n) is not None:
        return H[n]
    H[n] = g(n // 2) + h(n // 2) if n % 2 == 0 else 0
    return H[n]


def main():
    print(g(10**25) + h(10**25))


if __name__ == "__main__":
    sys.exit(main())
