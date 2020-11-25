// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

unsigned int seed = 131;

int64_t s = 0, total = 0;
int ok, major, major_left, minor_left;

int64_t multi_mod(int64_t a, int64_t b, int64_t c) {
  int64_t ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % c;
    }
    a = (a << 1) % c;
    b >>= 1;
  }

  return ans;
}

bool witness(int64_t a, int64_t n) {
  int64_t ans = 1, t = n - 1;
  while (t) {
    if (t & 1) {
      ans = multi_mod(ans, a, n);
    }
    int64_t x = a;
    a = multi_mod(a, a, n);
    if (a == 1 && x != 1 && x != n - 1) {
      return true;
    }
    t >>= 1;
  }

  return ans != 1;
}

bool miller_robin(int64_t n, int s) {
  if (n == 2) {
    return true;
  }
  if (n < 2 || !(n & 1)) {
    return false;
  }
  for (int i = 0; i < s; i++) {
    int64_t a = rand_r(&seed) % (n - 2) * rand_r(&seed) % (n - 2) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}

void dfs() {
  if (s >= 1000000000LL) {
    if (miller_robin(s, 10)) {
      ok = 1;
      total += s;
    }
    return;
  }
  for (int i = s == 0 ? 1 : 0; i < 10; i++) {
    if (i == major && major_left) {
      major_left--;
      s = s * 10 + i;
      dfs();
      s /= 10;
      major_left++;
    } else if (i != major && minor_left) {
      minor_left--;
      s = s * 10 + i;
      dfs();
      s /= 10;
      minor_left++;
    }
  }
}

int main() {
  for (int d = 0; d < 10; d++) {
    ok = 0;
    major = d;
    major_left = 10;
    minor_left = 0;
    while (!ok) {
      major_left--;
      minor_left++;
      dfs();
    }
  }

  printf("%ld\n", total);
  return 0;
}
