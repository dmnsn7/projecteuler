// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::set;
using std::swap;
using std::vector;

const int N = 1500001;
const int SEED = 1000000007;

vector<int> min_div;
map<int64_t, vector<int>> M;

vector<int> get_min_div(int n) {
  vector<int> p;
  vector<int> d(n, 0);
  for (int i = 2; i < n; i++) {
    if (d[i] == 0) {
      d[i] = i;
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && p[j] * i < n; j++) {
      d[p[j] * i] = p[j];
      if (i % p[j] == 0) break;
    }
  }

  return d;
}

vector<int> get_fac(int n) {
  vector<int> ans;
  while (n != 1) {
    int d = min_div[n];
    if (n / d % d == 0) {
      n /= d * d;
    } else {
      ans.push_back(d);
      n /= d;
    }
  }

  return ans;
}

int64_t get_hash(vector<int> v) {
  int64_t ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans = ans * SEED + v[i];
  }

  return ans;
}

struct cmp {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < 3; i++) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
    return false;
  }
};

int main() {
  map<int, set<vector<int>, cmp>> SOL;
  min_div = get_min_div(N);
  for (int i = 1; i < N; i++) {
    vector<int> v = get_fac(i);
    int64_t hash_val = get_hash(v);
    for (int j = 0; j < M[hash_val].size(); j++) {
      if ((i - M[hash_val][j]) % 2 == 0) {
        int a = (i + M[hash_val][j]) / 2;
        int b = (i - M[hash_val][j]) / 2;
        int c = sqrt(1.0 * i * M[hash_val][j] + 0.5);
        if (b < c) swap(b, c);
        if (a + b + c <= 1500000) {
          SOL[a + b + c].insert(vector<int>{a, b, c});
        }
      }
    }
    M[hash_val].push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < SOL.size(); i++) {
    if (SOL[i].size() == 1) {
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
