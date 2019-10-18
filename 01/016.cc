// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;

const int N = 1000;

string multi_2(string s) {
  string t;
  int carry = 0;
  for (int i = 0; i < s.length(); i++) {
    int digit = carry + (s[i] - '0') * 2;
    t += digit % 10 + '0';
    carry = digit / 10;
  }

  if (carry) {
    t += carry + '0';
  }

  return t;
}

int main() {
  string num = "1";
  for (int i = 0; i < N; i++) {
    num = multi_2(num);
  }

  int sum = 0;
  for (int i = 0; i < num.length(); i++) {
    sum += num[i] - '0';
  }

  printf("%d\n", sum);

  return 0;
}
