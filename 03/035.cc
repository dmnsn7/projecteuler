// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::string;
using std::to_string;
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
         it != prime.end() && *it * i < n; ++it) {
      is_prime[*it * i] = false;
      if (i % *it == 0) {
        break;
      }
    }
  }

  return prime;
}

string roll(string s) {
  return string(s.begin() + 1, s.end()) + string(s.begin(), s.begin() + 1);
}

int main() {
  set<int> prime = prime_sieve(N);
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    int flag = true;
    string si = to_string(i);
    for (int j = 0; j < si.length() && flag; j++) {
      int num;
      sscanf(si.c_str(), "%d", &num);
      if (prime.find(num) == prime.end()) {
        flag = false;
      }
      si = roll(si);
    }

    cnt += flag;
  }

  printf("%d\n", cnt);

  return 0;
}
