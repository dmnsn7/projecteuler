// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::string;
using std::to_string;
using std::vector;

const int D = 1000000;

set<int> prime_sieve(int n) {
  vector<bool> is_prime(n, true);
  set<int> prime;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.insert(i);
    }
    for (set<int>::iterator it = prime.begin();
         it != prime.end() && *it * i < n; ++it) {
      is_prime[*it * i] = false;
      if (i % *it == 0) {
        break;
      }
    }
  }

  return prime;
}

bool is_trunc(int n, const set<int>& prime) {
  if (n < 10) {
    return false;
  }

  string sn = to_string(n);
  for (int i = 1; i <= sn.length(); i++) {
    string tsn = string(sn.begin(), sn.begin() + i);
    int tmp;
    sscanf(tsn.c_str(), "%d", &tmp);
    if (prime.find(tmp) == prime.end()) {
      return false;
    }

    tsn = string(sn.begin() + sn.length() - i, sn.end());
    sscanf(tsn.c_str(), "%d", &tmp);
    if (prime.find(tmp) == prime.end()) {
      return false;
    }
  }

  return true;
}

int main() {
  set<int> prime = prime_sieve(D);
  int sum = 0;
  for (set<int>::iterator it = prime.begin(); it != prime.end(); ++it) {
    if (is_trunc(*it, prime)) {
      sum += *it;
    }
  }

  printf("%d\n", sum);

  return 0;
}
