// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::min;
using std::vector;

const int N = 12;

int main() {
  vector<int> b(1 << N, 0);
  vector<int> h(1 << N, 0);
  vector<int> l(1 << N, 0);
  for (int i = 1; i < 1 << N; i++) {
    b[i] = b[i & (i - 1)] + 1;
    l[i] = i - (i & (i - 1));
    h[i] = (i & (i - 1)) == 0 ? i : h[i & (i - 1)];
  }
  int ans = 0;
  for (int i = 1; i < 1 << N; i++) {
    for (int j = i + 1; j < 1 << N; j++) {
      if (b[i] != b[j] || i & j) {
        continue;
      }
      int ti = min(i, j), tj = max(i, j);
      while (ti < tj) {
        ti -= h[ti];
        tj -= h[tj];
      }
      if (ti != 0) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
