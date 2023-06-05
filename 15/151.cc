// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::vector;

map<vector<int>, double> M;

double dfs(vector<int> v) {
  if (v.size() == 0) {
    return 0;
  }
  if (v.back() == 1) {
    return 1;
  }
  if (M.find(v) != M.end()) {
    return M[v];
  }
  double ans = 0;
  if (v.size() == 1) {
    ans += 1;
  }
  for (int i = 0; i < v.size(); i++) {
    vector<int> u = {};
    for (int j = 0; j < v.size(); j++) {
      if (i != j) {
        u.push_back(v[j]);
      }
    }
    for (int j = 1; j < v[i]; j <<= 1) {
      u.push_back(j);
    }
    sort(u.begin(), u.end());
    ans += dfs(u) / v.size();
  }

  return M[v] = ans;
}

int main() {
  printf("%.6f\n", dfs({16}) - 2);

  return 0;
}
