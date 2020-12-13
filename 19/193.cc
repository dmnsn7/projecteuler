// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

using std::vector;

vector<int> prime_sieve(int n) {
  vector<int> prime;
  vector<bool> is_prime(n, true);
  vector<int> m(n, 1);
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      m[i] = -1;
    }
    for (int j = 0; j < prime.size() && prime[j] * i < n; j++) {
      is_prime[prime[j] * i] = false;
      m[prime[j] * i] = -m[i];
      if (i % prime[j] == 0) {
        m[prime[j] * i] = 0;
        break;
      }
    }
  }

  return m;
}

int main() {
  int64_t ans = 0;
  vector<int> m = prime_sieve((1 << 25) + 1);
  for (int i = 1; i < (1 << 25) + 1; i++) {
    ans += (1LL << 50) / i / i * m[i];
  }
  printf("%ld\n", ans);
  return 0;
}
