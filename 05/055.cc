// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 10000;
const int K = 50;

vector<int> sum(vector<int> a, vector<int> b) {
  vector<int> c;
  int carry = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++) {
    if (i < a.size()) {
      carry += a[i];
    }
    if (i < b.size()) {
      carry += b[i];
    }
    c.push_back(carry % 10);
    carry /= 10;
  }

  while (carry) {
    c.push_back(carry % 10);
    carry /= 10;
  }

  return c;
}

bool is_palin(vector<int> v) {
  for (int i = 0; i < v.size() / 2; i++) {
    if (v[i] != v[v.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

vector<int> get_reverse(vector<int> v) {
  reverse(v.begin(), v.end());

  return v;
}

int is_lychrel(int n) {
  vector<int> v, u;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }

  u = get_reverse(v);
  for (int i = 0; i < K; i++) {
    v = sum(v, u);
    u = get_reverse(v);
    if (is_palin(v)) {
      return false;
    }
  }

  return true;
}

int main() {
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    cnt += is_lychrel(i) ? 1 : 0;
  }

  printf("%d\n", cnt);

  return 0;
}
