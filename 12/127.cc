// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::set;
using std::vector;

vector<int> prime_sieve(int n) {
  vector<int> prime;
  vector<int> rad(n, 1);
  for (int i = 2; i < n; i++) {
    if (rad[i] == 1) {
      rad[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      rad[prime[j] * i] = rad[i] * (i % prime[j] == 0 ? 1 : prime[j]);
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return rad;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  vector<vector<int>> V(120000);
  vector<int> rad = prime_sieve(120000);
  int64_t ans = 0;
  for (int i = 1; i < 120000; i++) {
    if (rad[i] < i) {
      V[rad[i]].push_back(i);
      set<int> S;
      for (int j = 1; j < i / rad[i]; j++) {
        for (int k = 0; k < V[j].size(); k++) {
          if (gcd(i, V[j][k]) != 1) {
            continue;
          }
          if (rad[V[j][k]] * rad[i - V[j][k]] < i / rad[i]) {
            S.insert(min(V[j][k], i - V[j][k]));
          }
        }
      }
      if (S.size()) {
        ans += i * S.size();
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
