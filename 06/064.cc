// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::make_pair;
using std::map;
using std::pair;

const int N = 10000;

int main() {
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    int c = sqrt(i + 0.5);
    if (c * c == i) {
      continue;
    }
    map<pair<int, int>, int> M;
    int x = 0, y = 1, depth = 1;
    while (true) {
      int delta = (sqrt(i) + x) / y;
      x -= y * delta;
      y = (i - x * x) / y;
      x = -x;
      if (M.find(make_pair(x, y)) != M.end()) {
        if ((depth - M[make_pair(x, y)]) % 2 == 1) {
          ans++;
        }
        break;
      }
      M[make_pair(x, y)] = depth++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
