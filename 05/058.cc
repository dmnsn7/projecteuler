// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int RATE = 10;

bool is_prime(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int prime_cnt = 0;
  int num = 1, target;
  for (int i = 1;; i++) {
    for (int j = 0; j < 4; j++) {
      num += i * 2;
      prime_cnt += is_prime(num) ? 1 : 0;
    }

    target = i * 2 + 1;
    if (i * 4 + 1 > RATE * prime_cnt) {
      break;
    }
  }

  printf("%d\n", target);

  return 0;
}
