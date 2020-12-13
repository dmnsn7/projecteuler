// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::min;

int64_t DP[2][10][10][10];

int main() {
  int64_t ans = 0;
  int flag = 0;
  for (int i = 1; i <= 9; i++) {
    DP[flag][i][i][i] = 1;
  }
  for (int i = 2; i <= 40; i++) {
    flag ^= 1;
    memset(DP[flag], 0, sizeof(DP[flag]));
    for (int d = 0; d < 10; d++) {
      for (int l = 0; l < 10; l++) {
        for (int r = l; r < 10; r++) {
          if (d > 0) {
            DP[flag][d - 1][min(l, d - 1)][max(d - 1, r)] +=
                DP[flag ^ 1][d][l][r];
          }
          if (d < 9) {
            DP[flag][d + 1][min(l, d + 1)][max(d + 1, r)] +=
                DP[flag ^ 1][d][l][r];
          }
        }
      }
    }
    for (int d = 0; d < 10; d++) {
      ans += DP[flag][d][0][9];
    }
  }

  printf("%ld\n", ans);
  return 0;
}
