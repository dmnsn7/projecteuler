// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::make_pair;
using std::pair;
using std::vector;

const int N = 100000;
const int K = 10000;

vector<int> prime_sieve(int n) {
  vector<int> prime;
  vector<int> rad(n, 1);
  for (int i = 2; i < n; i++) {
    if (rad[i] == 1) {
      rad[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      rad[prime[j] * i] = rad[i] * (i % prime[j] == 0 ? 1 : prime[j]);
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return rad;
}

int main() {
  vector<int> rad = prime_sieve(N + 1);
  vector<pair<int, int>> V;
  for (int i = 1; i <= N; i++) {
    V.push_back(make_pair(rad[i], i));
  }

  sort(V.begin(), V.end());
  printf("%d\n", V[K - 1].second);
  return 0;
}
