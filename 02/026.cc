// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;

const int D = 1000;

int get_recycle_size(int n) {
  int remainder = 1;
  int id = 1;
  map<int, int> visited;

  while (visited[remainder] == 0) {
    visited[remainder] = id++;
    while (remainder != 0 && remainder < n) {
      remainder *= 10;
    }

    remainder %= n;
  }

  return remainder ? id - visited[remainder] : 0;
}

int main() {
  int max_recycle_size = 0;
  int target = 1;
  for (int i = 1; i < D; i++) {
    if (get_recycle_size(i) > max_recycle_size) {
      max_recycle_size = get_recycle_size(i);
      target = i;
    }
  }

  printf("%d\n", target);

  return 0;
}
