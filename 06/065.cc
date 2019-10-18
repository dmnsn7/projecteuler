// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 100;

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

int main() {
  BIGINT a(1), b(2);
  for (int i = 0; i < N - 1; i++) {
    int c = i % 3 != 1 ? 1 : (i / 3 + 1) * 2;
    a = a + b * c;
    std::swap(a, b);
  }

  int add_up = 0;
  for (int i = 0; i < b.data.size(); i++) {
    add_up += b.data[i];
  }

  printf("%d\n", add_up);

  return 0;
}
