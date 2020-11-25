// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

// 1 / n = 1 / (k + 1) n + 1 / (n / k + n);
// k = q / p, n % p == 0, n % q == 0, gcd(p, q) == 1;

const int N = 200000;

vector<vector<int>> F(N);

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      F[j].push_back(i);
    }
  }
  for (int i = 1; i < N; i++) {
    int ways = 0;
    for (int j = 0; j < F[i].size(); j++) {
      for (int k = j; k < F[i].size(); k++) {
        ways += gcd(F[i][j], F[i][k]) == 1;
      }
    }
    if (ways >= 1000) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
