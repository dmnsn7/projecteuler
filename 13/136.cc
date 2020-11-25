// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

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
  vector<int> pri = prime_sieve(50000000);
  int ans = 0;
  for (int i = 0; i < pri.size(); i++) {
    if (pri[i] % 4 == 3) {
      ans++;
    }
    if (pri[i] * 4 < 50000000) {
      ans++;
    }
    if (pri[i] * 16 < 50000000) {
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
