// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::next_permutation;
using std::vector;

vector<int> prime;
vector<int> M(1 << 9, 0);
vector<int> dp(1 << 9, -1);

int is_prime(int n) {
  if (n < 2) return 0;
  for (int i = 0; i < prime.size() && prime[i] <= n / prime[i]; i++) {
    if (n % prime[i] == 0) {
      return 0;
    }
  }
  return 1;
}

vector<int> prime_sieve(int n) {
  vector<int> p;
  vector<bool> is_p(n, true);
  for (int i = 2; i < n; i++) {
    if (is_p[i]) {
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && p[j] * i < n; j++) {
      is_p[p[j] * i] = false;
      if (i % p[j] == 0) {
        break;
      }
    }
  }

  return p;
}

inline int lowbit(int x) { return x - (x & (x - 1)); }

int dfs(int n) {
  if (n == 0) return 1;
  if (~dp[n]) return dp[n];
  int ans = 0;
  for (int i = 0; i < 1 << 9; i++) {
    if (i & lowbit(n) && (i & n) == i) {
      ans += dfs(n ^ i) * M[i];
    }
  }
  return dp[n] = ans;
}

int main() {
  prime = prime_sieve(100000);
  for (int i = 0; i < 512; i++) {
    vector<int> v;
    int t = 1, id = 0;
    for (int j = 0; j < 9; j++) {
      if (i & (1 << j)) {
        v.push_back(j + 1);
        t *= ++id;
      }
    }
    for (int j = 0; j < t; j++) {
      next_permutation(v.begin(), v.end());
      int p = 0;
      for (int k = 0; k < v.size(); k++) {
        p = p * 10 + v[k];
      }
      if (is_prime(p)) {
        M[i]++;
      }
    }
  }

  printf("%d\n", dfs(511));
  return 0;
}
