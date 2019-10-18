// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::string;
using std::vector;

const int N = 15;

const vector<string> GRID = {
    "75",
    "95 64",
    "17 47 82",
    "18 35 87 10",
    "20 04 82 47 65",
    "19 01 23 75 03 34",
    "88 02 77 73 07 63 67",
    "99 65 04 28 06 16 70 92",
    "41 41 26 56 83 40 80 70 33",
    "41 48 72 33 47 32 37 16 94 29",
    "53 71 44 65 25 43 91 52 97 51 14",
    "70 11 33 28 77 73 17 78 39 68 17 57",
    "91 71 52 38 17 14 91 43 58 50 27 29 48",
    "63 66 04 68 89 53 67 30 73 16 69 87 40 31",
    "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23",
};

int main() {
  int max_sum = 0;
  vector<int> dp;
  for (int i = 0; i < N; i++) {
    vector<int> dp_cur(i + 1, 0);
    for (int j = 0; j <= i; j++) {
      int num;
      sscanf(GRID[i].c_str() + 3 * j, "%d", &num);
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
