// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::vector;

const int A = 1000;
const int B = 1000;
const int N = 2001000;

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

  int max_len = 0, multi = 0;
  for (int i = -A + 1; i <= A - 1; i++) {
    for (int j = -B + 1; j <= B - 1; j++) {
      int len = -1;
      for (int k = 0; len == -1; k++) {
        int num = k * k + i * k + j;
        if (prime.find(num) == prime.end()) {
          len = k;
        }
      }

      if (len > max_len) {
        max_len = len;
        multi = i * j;
      }
    }
  }

  printf("%d\n", multi);

  return 0;
}
