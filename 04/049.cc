// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::string;
using std::to_string;
using std::vector;

const int LOW = 1000;
const int HIGH = 10000;
const int CNT = 3;
const int EXCEPTION = 1487;

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

bool is_equal(int a, int b) {
  string sa = to_string(a);
  string sb = to_string(b);
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());

  return sa == sb;
}

int main() {
  set<int> prime = prime_sieve(HIGH);
  string join;
  for (set<int>::iterator it = prime.begin(); it != prime.end(); ++it) {
    if (*it < LOW || *it == EXCEPTION) {
      continue;
    }
    for (set<int>::iterator jt = next(it); jt != prime.end(); ++jt) {
      int num_1 = *it;
      int num_2 = *jt;
      int num_3 = num_2 * 2 - num_1;
      if (prime.find(num_3) != prime.end() && is_equal(num_1, num_2) &&
          is_equal(num_2, num_3)) {
        join = to_string(num_1) + to_string(num_2) + to_string(num_3);
      }
    }
  }

  printf("%s\n", join.c_str());

  return 0;
}
