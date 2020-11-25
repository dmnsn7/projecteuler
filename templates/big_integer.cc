// Copyright [2020] <dmnsn7@gmail.com>
#include <bits/stdc++.h>

using std::vector;

struct BIGINT {
  std::vector<int> data;
  BIGINT() {}
  explicit BIGINT(int n) {
    while (n) {
      data.push_back(n % 10);
      n /= 10;
    }
  }

  BIGINT operator+(const BIGINT &to) const {
    BIGINT c;
    int carry = 0;
    for (int i = 0; i < data.size() || i < to.data.size(); i++) {
      if (i < data.size()) {
        carry += data[i];
      }
      if (i < to.data.size()) {
        carry += to.data[i];
      }
      c.data.push_back(carry % 10);
      carry /= 10;
    }
    while (carry) {
      c.data.push_back(carry % 10);
      carry /= 10;
    }
    return c;
  }

  BIGINT operator*(const int to) const {
    BIGINT c;
    int carry = 0;
    for (int i = 0; i < data.size(); i++) {
      carry += data[i] * to;
      c.data.push_back(carry % 10);
      carry /= 10;
    }
    while (carry) {
      c.data.push_back(carry % 10);
      carry /= 10;
    }
    return c;
  }
};

int main() { return 0; }
