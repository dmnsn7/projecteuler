// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

using std::vector;

int64_t DP[31][2][3];

int64_t dfs(int n, int l, int a) {
  if (n == 1) {
    return l + a <= 1 ? 1 : 0;
  }
  if (DP[n][l][a] != -1) {
    return DP[n][l][a];
  }
  if (a != 0) {
    return DP[n][l][a] = dfs(n - 1, l, a - 1);
  }
  int64_t ans = dfs(n - 1, l, 0) + dfs(n - 1, l, 1) + dfs(n - 1, l, 2);
  if (l) {
    ans += dfs(n - 1, 0, 0) + dfs(n - 1, 0, 1) + dfs(n - 1, 0, 2);
  }
  return DP[n][l][a] = ans;
}

int main() {
  memset(DP, -1, sizeof(DP));
  int64_t ans = dfs(30, 0, 0) + dfs(30, 0, 1) + dfs(30, 0, 2) + dfs(30, 1, 0) +
                dfs(30, 1, 1) + dfs(30, 1, 2);
  printf("%ld\n", ans);
  return 0;
}
