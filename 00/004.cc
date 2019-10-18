// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

bool is_palin(int num) {
  vector<int> digit;
  while (num) {
    digit.push_back(num % 10);
    num /= 10;
  }

  for (int i = 0; i < digit.size() - 1 - i; i++) {
    if (digit[i] != digit[digit.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int max_palin = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int multi = i * j;
      if (multi > max_palin && is_palin(multi)) {
        max_palin = multi;
      }
    }
  }

  printf("%d\n", max_palin);

  return 0;
}
