// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

bool is_prime(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool is_ok(int n) {
  for (int i = 0; 2 * i * i < n; i++) {
    if (is_prime(n - 2 * i * i)) {
      return true;
    }
  }

  return false;
}

int main() {
  int target;
  for (int i = 1;; i += 2) {
    if (!is_ok(i)) {
      target = i;
      break;
    }
  }

  printf("%d\n", target);

  return 0;
}
