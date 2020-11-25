// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int main() {
  int ans = 0;
  for (int i = 3; i <= 33333333; i++) {
    int a = i, b = i + 1;
    int c = sqrt(1.0 * a * a + 1.0 * b * b + 0.5);
    if (1ll * a * a + 1ll * b * b == 1ll * c * c) {
      ans += 100000000 / (a + b + c);
    }
  }
  printf("%d\n", ans);
  return 0;
}
