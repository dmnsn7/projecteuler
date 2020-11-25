#!/usr/bin/env python3
import sys


def main():
    ans, max_x = 0, 0
    for i in range(2, 1001):
        if int((i + 0.5)**0.5)**2 == i:
            continue
        x, y, depth, D, M = 0, 1, 1, [], {}
        while True:
            delta = int((i**0.5 + x) / y)
            D.append(delta)
            x = y * delta - x
            y = (i - x * x) / y
            if (x, y) in M.keys():
                break
            M[(x, y)] = depth
            depth += 1
        p, q = 1, 0
        for j in range(len(D) - 2, -1, -1):
            p, q = q + p * D[j], p
        if len(D) % 2 == 0:
            p, q = 2 * p * p + 1, 2 * p * q
        if p > max_x:
            max_x, ans = p, i
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
