// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::vector;

const int N = 8000;
const int UP = 50000000;

vector<int> prime_sieve(int n) {
  vector<int> prime;
  vector<bool> is_prime(n, true);
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      is_prime[prime[j] * i] = false;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return prime;
}

int main() {
  vector<vector<int>> V(4);
  V[0] = prime_sieve(N);
  for (int i = 1; i < 4; i++) {
    for (int j = 0; j < V[i - 1].size(); j++) {
      int to_add = V[i - 1][j] * V[0][j];
      if (to_add <= UP) {
        V[i].push_back(to_add);
      } else {
        break;
      }
    }
  }

  set<int> S;
  for (int i = 0; i < V[1].size() && V[1][i] <= UP; i++) {
    for (int j = 0; j < V[2].size() && V[1][i] + V[2][j] <= UP; j++) {
      for (int k = 0; k < V[3].size() && V[1][i] + V[2][j] + V[3][k] <= UP;
           k++) {
        S.insert(V[1][i] + V[2][j] + V[3][k]);
      }
    }
  }

  printf("%ld\n", S.size());
  return 0;
}
