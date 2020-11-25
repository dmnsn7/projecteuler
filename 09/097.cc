// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int64_t MOD = 10000000000ll;

int64_t multi_mod(int64_t a, int64_t b, int64_t c) {
  int64_t ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % c;
    }
    b >>= 1;
    a = (a + a) % c;
  }

  return ans;
}

int64_t pow_mod(int64_t a, int64_t b, int64_t c) {
  int64_t ans = 1;
  while (b) {
    if (b & 1) {
      ans = multi_mod(ans, a, c);
    }
    b >>= 1;
    a = multi_mod(a, a, c);
  }

  return ans % c;
}

int main() {
  int64_t ans = pow_mod(2, 7830457, MOD);
  ans = multi_mod(ans, 28433, MOD) + 1;
  printf("%ld\n", ans);
  return 0;
}
