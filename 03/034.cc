// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int fac(int n) { return n ? n * fac(n - 1) : 1; }

const int D = 8 * fac(9);

int main() {
  int sum = 0;
  for (int i = 10; i <= D; i++) {
    int ti = i, score = 0;
    while (ti) {
      score += fac(ti % 10);
      ti /= 10;
    }

    sum += score == i ? i : 0;
  }

  printf("%d\n", sum);

  return 0;
}
