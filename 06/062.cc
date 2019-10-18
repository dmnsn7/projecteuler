// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::pair;
using std::string;
using std::to_string;

const int N = 10000;
const int M = 5;

int main() {
  map<string, pair<int, int64_t>> m;
  int64_t target;
  for (int i = 0; i < N; i++) {
    int64_t num = (int64_t)i * i * i;
    string s = to_string(num);
    sort(s.begin(), s.end());
    if (m.find(s) == m.end()) {
      m[s] = {1, num};
    } else {
      m[s].first++;
    }

    if (m[s].first >= M) {
      target = m[s].second;
      break;
    }
  }

  printf("%ld\n", target);

  return 0;
}
