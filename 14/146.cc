// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

unsigned int seed = 131;

uint64_t multi_mod(uint64_t a, uint64_t b, uint64_t c) {
  uint64_t ans = 0;
  while (b) {
    ans = (ans + a * (b % 800)) % c;
    a = a * 800 % c;
    b /= 800;
  }

  return ans;
}

int witness(uint64_t a, uint64_t n) {
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

int miller_robin(uint64_t n, int s) {
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

int main() {
  uint64_t ans = 0;
  for (uint64_t i = 10; i < 150000000; i += 10) {
    if (i * i % 7 == 2 && miller_robin(i * i + 1, 3) &&
        miller_robin(i * i + 3, 3) && miller_robin(i * i + 7, 3) &&
        miller_robin(i * i + 9, 3) && miller_robin(i * i + 13, 3) &&
        miller_robin(i * i + 27, 3) && !miller_robin(i * i + 21, 3)) {
      ans += i;
    }
  }

  printf("%lu\n", ans);
  return 0;
}
