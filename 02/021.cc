// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 10000;

int get_fac_sum(int n) {
  int fac_sum = 1, tn = n;
  for (int i = 2; i <= tn / i; i++) {
    if (tn % i == 0) {
      int to_multi = 1, base = 1;
      while (tn % i == 0) {
        base *= i;
        to_multi += base;
        tn /= i;
      }
      fac_sum *= to_multi;
    }
  }

  if (tn != 1) {
    fac_sum *= tn + 1;
  }

  return fac_sum - n;
}

bool is_amic(int n) {
  return get_fac_sum(n) != n && get_fac_sum(get_fac_sum(n)) == n;
}

int main() {
  int amic_sum = 0;
  for (int i = 2; i < N; i++) {
    amic_sum += is_amic(i) ? i : 0;
  }

  printf("%d\n", amic_sum);

  return 0;
}
