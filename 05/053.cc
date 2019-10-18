// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;

const int N = 100;
const int M = 1000000;

bool is_ok(int a, int b) {
  int comb = 1;
  b = min(b, a - b);
  for (int i = 1; i <= b; i++) {
    comb = comb * (a + 1 - i) / i;
    if (comb > M) {
      return true;
    }
  }

  return false;
}

int main() {
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      cnt += is_ok(i, j) ? 1 : 0;
    }
  }

  printf("%d\n", cnt);

  return 0;
}
