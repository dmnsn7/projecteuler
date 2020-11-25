// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 1000001;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  double min_diff = 1e9;
  int ans = 0;
  for (int i = 8; i < N; i++) {
    int s = static_cast<int>(i * 3.0 / 7.0);
    while (gcd(s, i) != 1) s--;
    if (min_diff > 3.0 / 7.0 - 1.0 * s / i) {
      min_diff = 3.0 / 7.0 - 1.0 * s / i;
      ans = s;
    }
  }

  printf("%d\n", ans);
  return 0;
}
