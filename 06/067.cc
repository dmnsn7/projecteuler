// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::vector;

const int N = 100;

int main() {
  int max_sum = 0;
  vector<int> dp;
  for (int i = 0; i < N; i++) {
    vector<int> dp_cur(i + 1, 0);
    for (int j = 0; j <= i; j++) {
      int num;
      scanf("%d", &num);
      if (i == 0) {
        dp_cur[j] = num;
      } else if (j == 0) {
        dp_cur[j] = dp[j] + num;
      } else if (j == i) {
        dp_cur[j] = dp[j - 1] + num;
      } else {
        dp_cur[j] = max(dp[j], dp[j - 1]) + num;
      }

      max_sum = max(max_sum, dp_cur[j]);
    }

    dp = dp_cur;
  }

  printf("%d\n", max_sum);

  return 0;
}
