#!/usr/bin/env python3
import sys

rt = list(range(0, 40))


def root(u):
    if rt[u] == u:
        return u
    rt[u] = root(rt[u])
    return rt[u]


def main():
    e = []
    for i in range(0, 40):
        for j, st in enumerate(input().split(',')):
            if st != '-' and i > j:
                e.append((int(st), i, j))
    e = sorted(e)
    ans = 0
    for x in e:
        w, u, v = x
        if root(u) != root(v):
            rt[root(u)] = root(v)
        else:
            ans += w
    print(ans)


if __name__ == "__main__":
    sys.exit(main())
