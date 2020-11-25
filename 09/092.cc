// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 10000000;

vector<int> DP(N, 0);

int get_next(int n) {
  int ans = 0;
  while (n) {
    ans += (n % 10) * (n % 10);
    n /= 10;
  }
  return ans;
}

int dfs(int n) {
  if (DP[n]) return DP[n];
  if (n == 1 || n == 89) return DP[n] = n;
  return DP[n] = dfs(get_next(n));
}

int main() {
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (dfs(i) == 89) {
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
