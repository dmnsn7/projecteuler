// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 101;

int DP[N][N];

int dfs(int n, int m) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (DP[n][m]) return DP[n][m];
  int ans = 0;
  for (int i = m; i <= n; i++) {
    ans += dfs(n - i, i);
  }
  return DP[n][m] = ans;
}

int main() {
  printf("%d\n", dfs(100, 1) - 1);

  return 0;
}
