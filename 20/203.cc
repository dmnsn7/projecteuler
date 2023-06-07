// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

using std::set;
using std::vector;

int N = 51;

bool squarefree(long long n) {
  for (int i = 2; i <= N; i++) {
    if (n % i == 0 && n / i % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  set<long long> S;
  vector<long long> v[2] = {{1}, {}};
  int flag = 0;
  for (int i = 2; i <= N; i++) {
    v[flag ^ 1] = {};
    for (int j = 0; j < i; j++) {
      long long num = j == 0 || j == i - 1 ? 1 : v[flag][j - 1] + v[flag][j];
      v[flag ^ 1].push_back(num);
      S.insert(num);
    }
    flag ^= 1;
  }
  long long ans = 0;
  for (auto it : S) {
    ans += squarefree(it) ? it : 0;
  }
  printf("%lld\n", ans);
  return 0;
}
