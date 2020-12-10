// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

int ans = 0;
vector<int> G;
unordered_map<int64_t, int> M;

int64_t get_hash(vector<int> v) {
  int64_t h = 0;
  for (int i = 0; i < v.size(); i++) {
    h = h * 1000000007 + v[i];
  }
  return h;
}

void dfs() {
  if (G.size() == 7) {
    int s = G[0] + G[1] + G[2] + G[3];
    int x = s - G[4] - G[5] - G[6];
    if (x >= 0 && x <= 9) {
      vector<int> v = {s,        G[0] + G[4], G[1] + G[5], G[2] + G[6],
                       G[3] + x, G[0] + G[5], G[3] + G[6]};
      M[get_hash(v)]++;
    }
    return;
  }
  for (int i = 0; i < 10; i++) {
    G.push_back(i);
    dfs();
    G.pop_back();
  }
}

void dfs2() {
  if (G.size() == 7) {
    int s = G[0] + G[1] + G[2] + G[3];
    int x = s - G[4] - G[5] - G[6];
    if (x >= 0 && x <= 9) {
      vector<int> v = {s,
                       s - G[0] - G[4],
                       s - G[1] - G[5],
                       s - G[2] - G[6],
                       s - G[3] - x,
                       s - G[2] - x,
                       s - G[1] - G[4]};
      ans += M[get_hash(v)];
    }
    return;
  }
  for (int i = 0; i < 10; i++) {
    G.push_back(i);
    dfs2();
    G.pop_back();
  }
}

int main() {
  dfs();
  dfs2();
  printf("%d\n", ans);
  return 0;
}
