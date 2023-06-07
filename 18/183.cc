// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 10000;

int main() {
  int ans = 0;
  for (int i = 5; i <= N; i++) {
    double optimal = i / exp(1);
    double f = floor(optimal);
    double c = ceil(optimal);
    int x = (int)(f * log(i / f) < c * log(i / c) ? c : f);
    while (x % 2 == 0) {
      x /= 2;
    }
    while (x % 5 == 0) {
      x /= 5;
    }
    ans += i % x == 0 ? -i : i;
  }
  printf("%d\n", ans);
  return 0;
}
