// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 4000001;
const int NUM = 2000000;

int main() {
  vector<int> V;
  for (int i = 0, j = 1; j < N; i++, j += i + 1) {
    V.push_back(j);
  }
  int min_diff = 1e9;
  int ans = 0;
  for (int i = 0; i < V.size(); i++) {
    int j = lower_bound(V.begin(), V.end(), NUM / V[i]) - V.begin();
    if (abs(V[i] * V[j] - NUM) < min_diff) {
      min_diff = abs(V[i] * V[j] - NUM);
      ans = (i + 1) * (j + 1);
    }
    if (j + 1 < V.size() && abs(V[i] * V[j + 1] - NUM) < min_diff) {
      min_diff = abs(V[i] * V[j + 1] - NUM);
      ans = (i + 1) * (j + 2);
    }
  }

  printf("%d\n", ans);
  return 0;
}
