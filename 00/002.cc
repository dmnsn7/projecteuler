// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int D = 4000000;

int main() {
  vector<int> fib = {1, 2};
  while (fib[fib.size() - 2] + fib[fib.size() - 1] <= D) {
    fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
  }

  int sum = 0;
  for (int i = 0; i < fib.size(); i++) {
    if (fib[i] % 2 == 0) {
      sum += fib[i];
    }
  }

  printf("%d\n", sum);

  return 0;
}
