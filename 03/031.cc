// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int SUM = 200;
const vector<int> PENNY = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
  vector<int> dp(SUM + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < PENNY.size(); i++) {
    vector<int> Tdp = dp;
    for (int j = 0; j + PENNY[i] <= SUM; j++) {
      Tdp[j + PENNY[i]] += Tdp[j];
    }

    dp = Tdp;
  }

  printf("%d\n", dp[SUM]);

  return 0;
}
