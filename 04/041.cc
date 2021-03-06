// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::vector;

const int N = 9;
const int M = 100000;

vector<int> prime;

vector<int> prime_sieve(int n) {
  vector<bool> is_p(n, true);
  vector<int> p;
  for (int i = 2; i < n; i++) {
    if (is_p[i]) {
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && p[j] * i < n; j++) {
      is_p[p[j] * i] = false;
      if (i % p[j] == 0) {
        break;
      }
    }
  }

  return p;
}

bool is_prime(int n) {
  for (int i = 0; i < prime.size() && prime[i] < n; i++) {
    if (n % prime[i] == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  prime = prime_sieve(M);
  string s;
  int fac = 1, max_prime = 2;
  for (int i = 1; i <= N; i++) {
    fac *= i;
    s += i + '0';
    for (int j = 0; j < fac; j++) {
      next_permutation(s.begin(), s.end());
      int num;
      sscanf(s.c_str(), "%d", &num);
      if (num > max_prime && is_prime(num)) {
        max_prime = num;
      }
    }
  }

  printf("%d\n", max_prime);

  return 0;
}
