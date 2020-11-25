// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::set;
using std::vector;

const int N = 12000;
const int M = 15000;

vector<vector<int>> V(M);

vector<int> F;
int origin_n, sum;

map<int, int> VISITED;

void dfs(int n) {
  if (n == 1) {
    int l = origin_n - sum + F.size();
    if (VISITED.find(l) == VISITED.end()) {
      VISITED[l] = origin_n;
    }
    return;
  }
  for (int i = 0; i < V[n].size(); i++) {
    if (F.size() && V[n][i] < F.back()) {
      continue;
    }
    F.push_back(V[n][i]);
    sum += V[n][i];
    dfs(n / V[n][i]);
    sum -= V[n][i];
    F.pop_back();
  }
}

int main() {
  for (int i = 2; i < M; i++) {
    for (int j = i; j < M; j += i) {
      V[j].push_back(i);
    }
  }
  for (int i = 2; i < M; i++) {
    origin_n = i;
    dfs(i);
  }

  int ans = 0;
  set<int> distinct;
  for (int i = 2; i <= N; i++) {
    distinct.insert(VISITED[i]);
  }
  for (set<int>::iterator it = distinct.begin(); it != distinct.end(); ++it) {
    ans += *it;
  }

  printf("%d\n", ans);
  return 0;
}
