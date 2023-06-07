// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

int main() {
  int ans = 0;
  for (int i = 2; i <= 15; i++) {
    double p = 1;
    for (int j = 1; j <= i; j++) {
      p *= pow(j * 2.0 / (i + 1), j);
    }
    ans += (int)floor(p);
  }
  printf("%d\n", ans);
  return 0;
}
