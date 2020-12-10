// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int64_t DP[2][10][10];

int main() {
  int flag = 0;
  DP[0][0][0] = 1;
  for (int i = 0; i < 20; i++) {
    flag ^= 1;
    memset(DP[flag], 0, sizeof(DP[flag]));
    for (int j = i ? 0 : 1; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          if (k + l + j <= 9) {
            DP[flag][l][j] += DP[flag ^ 1][k][l];
          }
        }
      }
    }
  }
  int64_t ans = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      ans += DP[flag][i][j];
    }
  }
  printf("%ld\n", ans);
  return 0;
}
