// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int main() {
  int64_t a = 5, b = 17, ans = 0;
  for (int i = 0; i < 10; i++) {
    int flag = 0;
    if (3 * a + 1 <= 1e9) {
      ans += 3 * a + 1;
      flag = 1;
    }
    if (3 * b - 1 < 1e9) {
      ans += 3 * b - 1;
      flag = 1;
    }
    if (!flag) {
      break;
    }
    int ta = -a + 4 * b + 2;
    int tb = -4 * a + 15 * b + 6;
    a = ta, b = tb;
  }

  printf("%ld\n", ans);
  return 0;
}
