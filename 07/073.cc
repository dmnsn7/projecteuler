// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 12001;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int ans = 0;
  for (int i = 5; i < N; i++) {
    int l = i / 3;
    int r = i / 2;
    for (int j = l + 1; j <= r; j++) {
      if (gcd(i, j) == 1) ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
