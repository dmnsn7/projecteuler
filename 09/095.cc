// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::vector;

const int N = 1000001;

vector<int64_t> NEXT;
vector<int> C;
vector<int> VISITED(N, 0);
vector<int> D(N);

vector<int64_t> get_facsum(int n) {
  vector<int> prime;
  vector<int64_t> facsum(n, 1);
  facsum[0] = 0;
  for (int i = 2; i < n; i++) {
    if (facsum[i] == 1) {
      facsum[i] = i + 1;
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      int64_t a = prime[j] * i, b = 1, fs = 1;
      while (a % prime[j] == 0) {
        b *= prime[j];
        fs += b;
        a /= prime[j];
      }
      facsum[prime[j] * i] = fs * facsum[a];
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return facsum;
}

int dfs(int64_t n) {
  if (NEXT[n] >= N) return 1e6;
  if (D[n]) return D[n];
  VISITED[n] = 1;
  if (VISITED[NEXT[n]] && !D[NEXT[n]]) {
    C.push_back(n);
    return D[n] = 1;
  }
  return D[n] = dfs(NEXT[n]) + 1;
}

int main() {
  NEXT = get_facsum(N);
  for (int i = 1; i < N; i++) {
    NEXT[i] -= i;
  }
  for (int i = 1; i < N; i++) {
    dfs(i);
  }
  int max_size = 0, ans = 0;
  for (int i = 0; i < C.size(); i++) {
    int sz = 1, minval = C[i], st = C[i];
    while (NEXT[st] != C[i]) {
      sz++;
      st = NEXT[st];
      minval = min(minval, st);
    }
    if (sz > max_size) {
      max_size = sz;
      ans = minval;
    } else if (sz == max_size) {
      ans = min(ans, minval);
    }
  }

  printf("%d\n", ans);
  return 0;
}
