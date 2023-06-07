// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

using std::vector;

const int N = 1000000000;
const int M = 100;

bool is_prime(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int> v[2] = {{1}, {}};
  int flag = 0;
  for (int i = 2; i <= M; i++) {
    if (!is_prime(i)) {
      continue;
    }
    v[flag ^ 1] = {};
    for (auto it : v[flag]) {
      for (long long j = 1; it * j <= N; j *= i) {
        v[flag ^ 1].push_back(it * j);
      }
    }
    flag ^= 1;
  }
  printf("%d\n", v[flag].size());
  return 0;
}
