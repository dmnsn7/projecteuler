// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 1000001;

vector<int> prime_sieve(int n) {
  vector<int> p;
  vector<int> phi(n, 0);
  for (int i = 2; i < n; i++) {
    if (phi[i] == 0) {
      phi[i] = i - 1;
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && p[j] * i < n; j++) {
      if (i % p[j] == 0) {
        phi[p[j] * i] = phi[i] * p[j];
        break;
      } else {
        phi[p[j] * i] = phi[i] * (p[j] - 1);
      }
    }
  }
  return phi;
}

int main() {
  vector<int> V = prime_sieve(N);
  double max_val = 0;
  int ans = 0;
  for (int i = 2; i < N; i++) {
    if (static_cast<double>(i) / V[i] > max_val) {
      max_val = static_cast<double>(i) / V[i];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
