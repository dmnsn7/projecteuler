// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 20;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return a / gcd(a, b) * b; }

int main() {
  int64_t ans = 1;
  for (int i = 1; i <= N; i++) {
    ans = lcm(ans, i);
  }

  printf("%ld\n", ans);

  return 0;
}
