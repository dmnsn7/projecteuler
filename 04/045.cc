// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int D = 144;

bool is_triangle(int n) {
  int num = sqrt(n * 2.0);
  return num * (num + 1) == n * 2;
}

bool is_penta(int n) {
  int num = sqrt(n * 6.0) / 3 + 1;
  return num * (3 * num - 1) == n * 2;
}

int main() {
  int target;
  for (int i = D;; i++) {
    int hex = i * (2 * i - 1);
    if (is_triangle(hex) && is_penta(hex)) {
      target = hex;
      break;
    }
  }

  printf("%d\n", target);

  return 0;
}
