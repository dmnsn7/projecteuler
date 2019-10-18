// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 1000;
const int64_t MOD = 10000000000LL;

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
  int64_t mod = 0;
  for (int i = 1; i <= N; i++) {
    mod += pow_mod(i, i, MOD);
    mod %= MOD;
  }

  printf("%ld\n", mod);

  return 0;
}
