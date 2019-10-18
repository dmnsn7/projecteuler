// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int K = 1000;

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

int main() {
  vector<int> a = {3}, b = {2};
  int cnt = 0;
  for (int i = 1; i <= K; i++) {
    cnt += b.size() > a.size() ? 1 : 0;
    b = sum(a, b);
    a = sum(a, b);
    swap(a, b);
  }

  printf("%d\n", cnt);

  return 0;
}
