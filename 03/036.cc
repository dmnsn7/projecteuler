// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::to_string;

const int N = 1000000;

bool is_palin(string s) {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int sum = 0;
  for (int i = 1; i < N; i++) {
    string base_10 = to_string(i);
    string base_2;
    for (int ti = i; ti; ti >>= 1) {
      base_2 += ti % 2 + '0';
    }

    sum += is_palin(base_10) && is_palin(base_2) ? i : 0;
  }

  printf("%d\n", sum);

  return 0;
}
