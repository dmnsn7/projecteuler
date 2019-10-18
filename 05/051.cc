// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::min;
using std::pair;
using std::string;
using std::to_string;
using std::vector;

const int N = 1000000;
const int CNT = 8;

vector<int> prime_sieve(int n) {
  vector<bool> is_prime(n, true);
  vector<int> prime;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && i * prime[j] < n; j++) {
      is_prime[i * prime[j]] = false;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return prime;
}

bool is_ok(string s) {
  sort(s.begin(), s.end());
  return distance(s.begin(), unique(s.begin(), s.end())) == 2;
}

vector<string> get_pattern(int n) {
  vector<string> V;
  string sn = to_string(n);
  for (int i = 1; i < 1 << sn.length(); i++) {
    string sm, sl, so;
    int m;
    for (int j = 0; j < sn.length(); j++) {
      sm += i & (1 << j) ? sn[j] : '0';
      sl += i & (1 << j) ? sn[j] : '*';
      so += i & (1 << j) ? '*' : sn[j];
    }
    sscanf(sm.c_str(), "%d", &m);
    if (is_ok(so)) {
      V.push_back(sl);
    }
  }

  return V;
}

int main() {
  map<string, pair<int, int>> M;
  vector<int> prime = prime_sieve(N);
  int target = 0;
  for (int i = 0; i < prime.size(); i++) {
    vector<string> pattern = get_pattern(prime[i]);
    for (int j = 0; j < pattern.size(); j++) {
      string s = pattern[j];
      if (M.find(s) == M.end()) {
        M[s] = {1, prime[i]};
      } else {
        M[s] = {M[s].first + 1, M[s].second};
      }
      if (M[s].first >= CNT) {
        target = target == 0 ? M[s].second : min(target, M[s].second);
      }
    }
  }

  printf("%d\n", target);

  return 0;
}
