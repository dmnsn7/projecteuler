// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool ok(int64_t n) {
  int64_t d = sqrt(n + 0.5);
  return d * d == n;
}

int main() {
  int64_t ans = 0;
  for (int64_t a = 2; a < 10000; a++) {
    for (int64_t b = 1; b < a; b++) {
      if (a * a * a * b * b + b * b >= 1e12) {
        break;
      }
      if (gcd(a, b) > 1) {
        continue;
      }
      for (int64_t c = 1;; c++) {
        int64_t n = a * a * a * b * c * c + c * b * b;
        if (n >= 1e12) {
          break;
        }
        if (ok(n)) {
          ans += n;
        }
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
