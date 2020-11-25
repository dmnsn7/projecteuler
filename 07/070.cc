// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::sort;
using std::string;
using std::to_string;
using std::vector;

const int N = 10000001;

vector<int> prime_sieve(int n) {
  vector<int> p;
  vector<int> phi(n, 0);
  for (int i = 2; i < n; i++) {
    if (phi[i] == 0) {
      phi[i] = i - 1;
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && p[j] * i < n; j++) {
      if (i % p[j] == 0) {
        phi[p[j] * i] = phi[i] * p[j];
        break;
      } else {
        phi[p[j] * i] = phi[i] * (p[j] - 1);
      }
    }
  }
  return phi;
}

int main() {
  vector<int> V = prime_sieve(N);
  double min_val = 1e9;
  int ans = 0;
  for (int i = 2; i < N; i++) {
    string sa = to_string(i);
    string sb = to_string(V[i]);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    if (sa != sb) continue;
    if (static_cast<double>(i) / V[i] < min_val) {
      min_val = static_cast<double>(i) / V[i];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
