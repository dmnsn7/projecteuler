// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::vector;

const int N = 100;

vector<int> to_vector(int n) {
  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }

  return v;
}

vector<int> multiply(vector<int> a, int b) {
  int carry = 0;
  for (int i = 0; i < a.size(); i++) {
    a[i] = a[i] * b + carry;
    carry = a[i] / 10;
    a[i] %= 10;
  }

  while (carry) {
    a.push_back(carry % 10);
    carry /= 10;
  }

  return a;
}

int main() {
  int max_digit_sum = 0;
  for (int i = 1; i < N; i++) {
    vector<int> p = to_vector(i);
    for (int j = 1; j < N; j++) {
      int digit_sum = 0;
      for (int k = 0; k < p.size(); k++) {
        digit_sum += p[k];
      }
      max_digit_sum = max(max_digit_sum, digit_sum);
      p = multiply(p, i);
    }
  }

  printf("%d\n", max_digit_sum);

  return 0;
}
