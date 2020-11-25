// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::to_string;

const int N = 100000000;
bool ok(int n) {
  while (n) {
    if (n % 10 % 2 == 0) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int main() {
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (i % 10 == 0) {
      continue;
    }
    string s = to_string(i);
    reverse(s.begin(), s.end());
    int rev;
    sscanf(s.c_str(), "%d", &rev);
    if (ok(rev + i)) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
