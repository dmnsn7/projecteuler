// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::make_pair;
using std::pair;
using std::set;
using std::string;
using std::to_string;
using std::vector;

const int N = 10000;
const int K = 5;

vector<int> prime;
set<pair<int, int>> s;
vector<int> v;
int min_sum, sum;

vector<int> prime_sieve(int n) {
  vector<bool> is_prime(n, true);
  vector<int> prime;
  for (int i = 2; i < n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && i * prime[j] < n; j++) {
      is_prime[prime[j] * i] = false;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }

  return prime;
}

bool is_prime(int n) {
  if (n < N) {
    vector<int>::iterator it = lower_bound(prime.begin(), prime.end(), n);
    return it != prime.end() && *it == n;
  }
  for (int i = 0; i < prime.size() && prime[i] <= n / prime[i]; i++) {
    if (n % prime[i] == 0) {
      return false;
    }
  }

  return true;
}

bool is_ok(int a, int b) {
  string s;
  int num;

  s = to_string(a) + to_string(b);
  sscanf(s.c_str(), "%d", &num);
  if (!is_prime(num)) {
    return false;
  }

  s = to_string(b) + to_string(a);
  sscanf(s.c_str(), "%d", &num);
  if (!is_prime(num)) {
    return false;
  }

  return true;
}

void dfs() {
  if (min_sum != 0 && sum >= min_sum) {
    return;
  }
  if (v.size() >= K) {
    min_sum = sum;
    return;
  }

  int lb;
  if (v.size() == 0) {
    lb = 0;
  } else {
    lb = upper_bound(prime.begin(), prime.end(), v.back()) - prime.begin();
  }
  for (int i = lb; i < prime.size(); i++) {
    bool flag = true;
    for (int j = 0; j < v.size() && flag; j++) {
      flag = flag && s.find(make_pair(v[j], prime[i])) != s.end();
    }
    if (flag) {
      v.push_back(prime[i]);
      sum += prime[i];
      dfs();
      sum -= prime[i];
      v.pop_back();
    }
  }
}

int main() {
  prime = prime_sieve(N);
  for (int i = 0; i < prime.size(); i++) {
    for (int j = i; j < prime.size(); j++) {
      if (is_ok(prime[i], prime[j])) {
        s.insert(make_pair(prime[i], prime[j]));
      }
    }
  }

  min_sum = 0;
  sum = 0;
  dfs();

  printf("%d\n", min_sum);

  return 0;
}
