// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::to_string;
using std::vector;

const int D = 1000000;

const vector<int> V = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main() {
  string s;
  for (int i = 1; s.length() < D; i++) {
    s += to_string(i);
  }

  int multi = 1;
  for (int i = 0; i < V.size(); i++) {
    multi *= s[V[i] - 1] - '0';
  }

  printf("%d\n", multi);

  return 0;
}
