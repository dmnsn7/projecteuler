// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::vector;

const int N = 1000000;

set<int> prime_sieve(int n) {
  vector<bool> is_prime(n, true);
  set<int> prime;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.insert(i);
    }
    for (set<int>::iterator it = prime.begin();
         it != prime.end() && i * *it < n; ++it) {
      is_prime[i * *it] = false;
      if (i % *it == 0) {
        break;
      }
    }
  }

  return prime;
}

int main() {
  set<int> prime = prime_sieve(N);
  int max_len = 1, target;
  for (set<int>::iterator it = prime.begin(); it != prime.end(); ++it) {
    int sum = 0;
    for (set<int>::iterator jt = it; jt != prime.end() && sum < N; ++jt) {
      sum += *jt;
      if (prime.find(sum) != prime.end() && distance(it, jt) + 1 > max_len) {
        max_len = distance(it, jt) + 1;
        target = sum;
      }
    }
  }

  printf("%d\n", target);

  return 0;
}
