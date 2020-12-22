// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::swap;
using std::vector;

vector<vector<int>> T = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1}};

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> c(9, vector<int>(9, 0));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        c[i][j] =
            (c[i][j] + static_cast<int64_t>(a[i][k]) * b[k][j]) % 100000000;
      }
    }
  }
  return c;
}

vector<vector<int>> pow_mod(vector<vector<int>> a, int64_t b) {
  vector<vector<int>> ans(9, vector<int>(9, 0));
  for (int i = 0; i < 9; i++) {
    ans[i][i] = 1;
  }
  while (b) {
    if (b & 1) {
      ans = multiply(ans, a);
    }
    b >>= 1;
    a = multiply(a, a);
  }

  return ans;
}

int main() {
  vector<vector<int>> M = pow_mod(T, 1000000000000LL);
  printf("%d\n", M[3][0]);
  return 0;
}
