#!/usr/bin/env python3
import sys


def ok(n):
    return int((n + 0.5)**0.5)**2 == n


def main():
    ans = 10**10
    for a in range(1, 1000):
        for b in range(1, 1000):
            if not ok(a * a + b * b):
                continue
            for c in range(a + 2, 1000, 2):
                if ok(b * b + c * c) and ok(a * a + b * b + c * c):
                    ans = min(ans, (3 * c * c + 2 * b * b + a * a) // 2)
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
