// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 4;
const int M = 4;

int get_prime_fac_cnt(int n) {
  int cnt = 0;
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      cnt++;
    }
  }

  if (n != 1) {
    cnt++;
  }

  return cnt;
}

int main() {
  int target;
  for (int i = 1;; i++) {
    bool flag = true;
    for (int j = i; j < i + N; j++) {
      flag = flag && get_prime_fac_cnt(j) == M;
    }

    if (flag) {
      target = i;
      break;
    }
  }

  printf("%d\n", target);

  return 0;
}
