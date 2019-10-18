// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::string;
using std::to_string;

const int D = 100000;

int get_pand(int n) {
  string s;
  for (int i = 1; s.length() < 9; i++) {
    s += to_string(n * i);
  }

  if (s.length() != 9) {
    return false;
  }

  string ts = s;
  sort(ts.begin(), ts.end());
  for (int i = 0; i < 9; i++) {
    if (ts[i] != '1' + i) {
      return false;
    }
  }

  int num;
  sscanf(s.c_str(), "%d", &num);

  return num;
}

int main() {
  int max_pand = 0;
  for (int i = 1; i < D; i++) {
    max_pand = max(max_pand, get_pand(i));
  }

  printf("%d\n", max_pand);

  return 0;
}
