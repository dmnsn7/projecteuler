// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int main() {
  int ans = 0;
  double max_val = 0;
  for (int i = 1; i <= 1000; i++) {
    int a = 0, b = 0;
    scanf("%d,%d", &a, &b);
    double val = log(a) * b;
    if (val > max_val) {
      max_val = val;
      ans = i;
    }
  }

  printf("%d\n", ans);
  return 0;
}
