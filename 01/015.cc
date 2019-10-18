// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int R = 20;
const int C = 20;

int64_t get_comb(int a, int b) {
  int64_t comb = 1;
  for (int i = 1; i <= b; i++) {
    comb = comb * (a - i + 1) / i;
  }

  return comb;
}

int main() {
  int64_t comb = get_comb(R + C, R);

  printf("%ld\n", comb);

  return 0;
}
