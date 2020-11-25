// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::vector;

const int N = 1000;

int main() {
  vector<int> s(500500);
  for (int i = 0, tmp = 0; i < 500500; i++) {
    tmp = (615949LL * tmp + 797807) % (1 << 20);
    s[i] = tmp - (1 << 19);
  }

  vector<vector<int64_t>> A(N, vector<int64_t>(N, 0));
  vector<vector<int64_t>> B(N, vector<int64_t>(N, 0));

  int64_t ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 && j == 0) {
        A[i][j] = s[i * (i + 1) / 2 + j];
        B[i][j] = s[i * (i + 1) / 2 + j];
      } else if (j == 0) {
        A[i][j] = A[i - 1][j] + s[i * (i + 1) / 2 + j];
        B[i][j] = B[i - 1][j] + s[i * (i + 1) / 2 + j];
      } else if (i == j) {
        A[i][j] = A[i][j - 1] + s[i * (i + 1) / 2 + j];
        B[i][j] = B[i - 1][j - 1] + s[i * (i + 1) / 2 + j];
      } else {
        A[i][j] = A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1] +
                  s[i * (i + 1) / 2 + j];
        B[i][j] = B[i - 1][j - 1] + B[i - 1][j] - B[i - 2][j - 1] +
                  s[i * (i + 1) / 2 + j];
      }
      for (int k = 0; k <= j; k++) {
        int64_t tmp = 0;
        if (i == j && k == 0) {
          tmp = A[i][j];
        } else if (i == j) {
          tmp = A[i][j] - A[i][k - 1];
        } else if (k == 0) {
          tmp = A[i][j] - B[i - 1][j];
        } else {
          tmp = A[i][j] - A[i][k - 1] - B[i - 1][j] + B[i - j + k - 1][k - 1];
        }
        ans = min(ans, tmp);
      }
    }
  }
  printf("%ld\n", ans);
  return 0;
}
