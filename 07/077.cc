// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 101;

int DP[N][N];

vector<int> P;

vector<int> prime_sieve(int n) {
  vector<int> prime;
  vector<bool> is_prime(n, true);
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      is_prime[prime[j] * i] = false;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return prime;
}

int dfs(int n, int m) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (DP[n][m]) return DP[n][m];
  int ans = 0;
  for (int i = lower_bound(P.begin(), P.end(), m) - P.begin(); P[i] <= n; i++) {
    if (P[i] < m) continue;
    ans += dfs(n - P[i], P[i]);
  }
  return DP[n][m] = ans;
}

int main() {
  P = prime_sieve(N);
  int ans = 0;
  for (int i = 2; i < N; i++) {
    bool isp = *lower_bound(P.begin(), P.end(), i) == i;
    if (dfs(i, 2) + (isp ? -1 : 0) > 5000) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);

  return 0;
}
