// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

unsigned int seed = 131;

uint64_t multi_mod(uint64_t a, uint64_t b, uint64_t c) {
  uint64_t ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % c;
    }
    a = (a << 1) % c;
    b >>= 1;
  }

  return ans;
}

bool witness(uint64_t a, uint64_t n) {
  uint64_t ans = 1, t = n - 1;
  while (t) {
    if (t & 1) {
      ans = multi_mod(ans, a, n);
    }
    uint64_t x = a;
    a = multi_mod(a, a, n);
    if (a == 1 && x != 1 && x != n - 1) {
      return true;
    }
    t >>= 1;
  }

  return ans != 1;
}

bool miller_robin(uint64_t n, int s) {
  if (n == 2) {
    return true;
  }
  if (n < 2 || !(n & 1)) {
    return false;
  }
  for (int i = 0; i < s; i++) {
    uint64_t a = rand_r(&seed) % (n - 2) * rand_r(&seed) % (n - 2) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}

int main() { return 0; }
