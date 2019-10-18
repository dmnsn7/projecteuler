// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 1000;

int main() {
  int low_3 = 3, high_3 = (N - 1) / 3 * 3;
  int low_5 = 5, high_5 = (N - 1) / 5 * 5;
  int low_15 = 15, high_15 = (N - 1) / 15 * 15;

  int sum_3 = (low_3 + high_3) * ((high_3 - low_3) / 3 + 1) / 2;
  int sum_5 = (low_5 + high_5) * ((high_5 - low_5) / 5 + 1) / 2;
  int sum_15 = (low_15 + high_15) * ((high_15 - low_15) / 15 + 1) / 2;

  int ans = sum_3 + sum_5 - sum_15;

  printf("%d\n", ans);

  return 0;
}
