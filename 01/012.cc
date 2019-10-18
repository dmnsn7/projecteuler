// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 20000;
const int M = 500;

int get_fac_cnt(int n) {
  int fac_cnt = 1;
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      int to_multi = 0;
      while (n % i == 0) {
        n /= i;
        to_multi++;
      }

      fac_cnt *= to_multi + 1;
    }
  }

  if (n != 1) {
    fac_cnt *= 2;
  }

  return fac_cnt;
}

int main() {
  for (int i = 1; i <= N; i++) {
    int sum = i * (i + 1) / 2;
    if (get_fac_cnt(sum) > M) {
      printf("%d\n", sum);
      break;
    }
  }

  return 0;
}
