// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int64_t N = 600851475143LL;

int main() {
  int64_t tn = N, max_prime_fac = 0;
  for (int i = 2; i <= tn / i; i++) {
    if (tn % i == 0) {
      max_prime_fac = i;
      while (tn % i == 0) {
        tn /= i;
      }
    }
  }
  if (tn != 1) {
    max_prime_fac = tn;
  }

  printf("%ld\n", max_prime_fac);

  return 0;
}
