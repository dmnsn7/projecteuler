// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 1001;

int main() {
  vector<int> V = {1, 24, 52, 32};
  for (int i = 0; i < N / 2; i++) {
    V = {V[0] + V[1], V[1] + V[2], V[2] + V[3], V[3]};
  }

  printf("%d\n", V[0]);

  return 0;
}
