// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int pow_mod(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (long long)ans * a % c;
    }
    b >>= 1;
    a = (long long)a * a % c;
  }

  return ans % c;
}

int main() {
  int ans = 1;
  for (int i = 1; i <= 1855; i++) {
    ans = pow_mod(1777, ans, 100000000);
  }
  printf("%d\n", ans);
  return 0;
}
