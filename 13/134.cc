// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::to_string;
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

int pow_mod(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = static_cast<int64_t>(ans) * a % c;
    }
    b >>= 1;
    a = static_cast<int64_t>(a) * a % c;
  }

  return ans % c;
}

int main() {
  vector<int> T(7, 1);
  for (int i = 1; i <= 6; i++) {
    T[i] = 10 * T[i - 1];
  }
  vector<int> pri = prime_sieve(1100000);
  int64_t ans = 0;
  for (int i = 2; i < pri.size(); i++) {
    if (pri[i] > 1000000) {
      break;
    }
    int t = T[to_string(pri[i]).length()];
    int n = pow_mod(t % pri[i + 1], pri[i + 1] - 2, pri[i + 1]);
    n = static_cast<int64_t>(n) * (pri[i + 1] - pri[i]) % pri[i + 1];
    ans += pri[i] + static_cast<int64_t>(n) * t;
  }
  printf("%ld\n", ans);
  return 0;
}
