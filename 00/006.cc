// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 100;

int main() {
  int sum_1 = N * (N + 1) / 2;
  int sum_2 = N * (N + 1) * (2 * N + 1) / 6;
  int ans = sum_1 * sum_1 - sum_2;

  printf("%d\n", ans);

  return 0;
}
