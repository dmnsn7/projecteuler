// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::vector;

const int N = 2000;
const int D[4][2] = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}};
int DP[2000][2000][4];

int main() {
  vector<int> g(N * N, 0);
  for (int i = 1; i <= N * N; i++) {
    if (i <= 55) {
      g[i - 1] =
          (100003 - 200003 * i + 300007LL * i * i * i) % 1000000 - 500000;
    } else {
      g[i - 1] = (g[i - 25] + g[i - 56] + 1000000) % 1000000 - 500000;
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < 4; k++) {
        DP[i][j][k] = g[i * N + j];
        int ti = i + D[k][0], tj = j + D[k][1];
        if (ti >= 0 && ti < N && tj >= 0 && tj < N) {
          DP[i][j][k] = max(DP[i][j][k], DP[ti][tj][k] + g[i * N + j]);
        }
        ans = max(ans, DP[i][j][k]);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
