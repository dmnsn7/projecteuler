// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 2000000;

vector<vector<int>> DP(2, vector<int>(N, -1));

int is_bouncy(int n, int flag) {
  if (n < 10) return 1;
  if (DP[flag][n] != -1) return DP[flag][n];
  if (flag == 1) {
    return DP[flag][n] = n % 10 >= n / 10 % 10 && is_bouncy(n / 10, flag);
  }
  return DP[flag][n] = n % 10 <= n / 10 % 10 && is_bouncy(n / 10, flag);
}

int main() {
  int is_b = 0, is_not_b = 0;
  for (int i = 1; i < N; i++) {
    if (is_bouncy(i, 1) || is_bouncy(i, 0)) {
      is_b++;
    } else {
      is_not_b++;
    }
    if (is_b * 99 == is_not_b) {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
