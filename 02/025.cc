// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int LEN = 1000;

vector<int> add(vector<int> a, vector<int> b) {
  vector<int> c;
  int carry = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++) {
    c.push_back(carry);
    if (i < a.size()) {
      c[c.size() - 1] += a[i];
    }
    if (i < b.size()) {
      c[c.size() - 1] += b[i];
    }
    carry = c[c.size() - 1] / 10;
    c[c.size() - 1] %= 10;
  }

  while (carry) {
    c.push_back(carry % 10);
    carry /= 10;
  }

  return c;
}

int main() {
  int idx = 2;
  vector<int> fib_0 = {1}, fib_1 = {1};
  while (fib_1.size() < LEN) {
    fib_0 = add(fib_1, fib_0);
    swap(fib_0, fib_1);
    idx++;
  }

  printf("%d\n", idx);

  return 0;
}
