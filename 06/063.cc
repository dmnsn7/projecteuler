// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

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
  int cnt = 0;
  for (int i = 1; i <= 9; i++) {
    vector<int> v = {i};
    for (int j = 1;; j++) {
      if (v.size() < j) {
        break;
      } else {
        v = multiply(v, i);
        cnt++;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}
