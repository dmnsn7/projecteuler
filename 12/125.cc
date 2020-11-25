// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::string;
using std::to_string;

const int N = 100000000;

bool is_palind(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.length() - 1 - i; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  set<int> S;
  for (int i = 1; i * i <= N; i++) {
    for (int j = i + 1, sum = i * i + j * j; sum <= N; j++, sum += j * j) {
      if (is_palind(sum)) {
        S.insert(sum);
      }
    }
  }

  int64_t ans = 0;
  for (set<int>::iterator it = S.begin(); it != S.end(); ++it) {
    ans += *it;
  }
  printf("%ld\n", ans);
  return 0;
}
