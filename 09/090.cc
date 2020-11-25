// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::vector;

int main() {
  vector<vector<int>> V;
  for (int i = 0; i < 1024; i++) {
    vector<int> tv;
    for (int j = 0; j < 10; j++) {
      if (i & (1 << j)) {
        tv.push_back(j);
      }
    }
    if (tv.size() == 6) {
      V.push_back(tv);
    }
  }

  int ans = 0;
  for (int i = 0; i < V.size(); i++) {
    for (int j = i + 1; j < V.size(); j++) {
      set<int> S;
      for (int k = 0; k < 6; k++) {
        for (int l = 0; l < 6; l++) {
          int tx = V[i][k] == 9 ? 6 : V[i][k];
          int ty = V[j][l] == 9 ? 6 : V[j][l];
          S.insert(tx * 10 + ty);
          S.insert(tx + ty * 10);
        }
      }
      if (S.find(1) != S.end() && S.find(4) != S.end() &&
          S.find(6) != S.end() && S.find(16) != S.end() &&
          S.find(25) != S.end() && S.find(36) != S.end() &&
          S.find(46) != S.end() && S.find(18) != S.end()) {
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
