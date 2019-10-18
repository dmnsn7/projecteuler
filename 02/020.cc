// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 100;

vector<int> multiply(vector<int> a, int b) {
  vector<int> multi;
  int carry = 0;
  for (int i = 0; i < a.size(); i++) {
    int num = a[i] * b + carry;
    multi.push_back(num % 10);
    carry = num / 10;
  }

  while (carry) {
    multi.push_back(carry % 10);
    carry /= 10;
  }

  return multi;
}

int main() {
  vector<int> fac = {1};
  for (int i = 1; i <= N; i++) {
    fac = multiply(fac, i);
  }

  int sum = 0;
  for (int i = 0; i < fac.size(); i++) {
    sum += fac[i];
  }

  printf("%d\n", sum);

  return 0;
}
