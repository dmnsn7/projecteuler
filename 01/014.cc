// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 1000000;

vector<int> DP(N, 0);

int dfs(int64_t n) {
  if (n == 1) {
    return 1;
  } else if (n < N) {
    return DP[n] = DP[n] ? DP[n] : dfs(n % 2 == 0 ? n / 2 : 3 * n + 1) + 1;
  } else {
    return dfs(n % 2 == 0 ? n / 2 : 3 * n + 1) + 1;
  }
}

int main() {
  int max_len = 1;
  int target = 1;
  for (int i = 1; i < N; i++) {
    int len = dfs(i);
    if (max_len < len) {
      max_len = len;
      target = i;
    }
  }

  printf("%d\n", target);

  return 0;
}
