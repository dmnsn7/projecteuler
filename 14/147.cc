// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::unordered_set;

const int N = 43;
const int M = 47;

int main() {
  unordered_set<int> S;
  int ans = N * (N + 1) * (N + 2) / 6 * M * (M + 1) * (M + 2) / 6;
  for (int i = 0; i <= 2 * N; i++) {
    for (int j = 0; j <= 2 * M; j++) {
      if ((i ^ j) & 1) {
        continue;
      }
      S.insert(i * 100 + j);
    }
  }
  for (int i = 0; i <= 2 * N; i++) {
    for (int j = 0; j <= 2 * M; j++) {
      if ((i ^ j) & 1) {
        continue;
      }
      for (int x = 1;; x++) {
        if (S.find((i - x) * 100 + (j + x)) == S.end()) {
          break;
        }
        for (int y = 1;; y++) {
          if (S.find((i + y) * 100 + (j + y)) == S.end()) {
            break;
          }
          if (S.find((i - x + y) * 100 + (j + x + y)) != S.end()) {
            ans += (N - (i + y + 1) / 2 + 1) * (M - (j + x + y + 1) / 2 + 1);
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
