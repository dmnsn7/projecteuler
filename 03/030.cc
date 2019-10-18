// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 5;
const int LEN = 6;

int pow(int a, int b) { return b ? a * pow(a, b - 1) : 1; }

int main() {
  int sum = 0;
  for (int i = 2; i < pow(10, LEN); i++) {
    int ti = i, score = 0;
    while (ti) {
      score += pow(ti % 10, N);
      ti /= 10;
    }

    sum += score == i ? i : 0;
  }

  printf("%d\n", sum);

  return 0;
}
