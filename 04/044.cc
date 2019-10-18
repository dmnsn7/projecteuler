// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 3000;
const int D = 1000000000;

bool is_penta(int n) {
  int num = sqrt(n * 6) / 3 + 1;
  return num * (3 * num - 1) == n * 2;
}

int main() {
  int min_diff = D;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int penta_i = i * (3 * i - 1) / 2;
      int penta_j = j * (3 * j - 1) / 2;
      int penta_k = penta_i + penta_j;
      int penta_l = penta_j + penta_k;
      if (is_penta(penta_k) && is_penta(penta_l) && min_diff > penta_i) {
        min_diff = penta_i;
      }
    }
  }

  printf("%d\n", min_diff);

  return 0;
}
