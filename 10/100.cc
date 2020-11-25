// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

// (2 * x - 1) ^ 2 - 2 * (2 * y - 1) ^ 2 = -1;
// x = (a + 1) / 2, y = (b + 1) / 2;
// a0 = 1, b0 = 1;
// a1 = 7, b1 = 5;
// a2 = 41, b2 = 29;
// a3 = 239, b3 = 169;
// a(n) = 3 * a(n - 1) + 4 * b(n - 1);
// b(n) = 2 * a(n - 1) + 3 * b(n - 1);

int main() {
  int64_t a = 1, b = 0;
  while (true) {
    int64_t ta = 3 * a + 4 * b;
    int64_t tb = 2 * a + 3 * b;
    int64_t x = (a + 1) / 2;
    int64_t y = (b + 1) / 2;
    if (x > 1e12) {
      printf("%ld\n", x - y);
      break;
    }
    a = ta;
    b = tb;
  }

  return 0;
}
