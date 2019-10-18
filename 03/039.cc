// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;

const int D = 1000;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  map<int, int> M;
  for (int a = 1; a <= D; a++) {
    for (int b = a + 1; b <= D; b++) {
      int c = static_cast<int>(sqrt(a * a + b * b + 0.5));
      if (gcd(a, b) == 1 && a * a + b * b == c * c) {
        M[a + b + c]++;
      }
    }
  }

  int max_comb = 0, target = 0;
  for (int i = 1; i <= D; i++) {
    int comb = 0;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
      if (i % it->first == 0) {
        comb += it->second;
      }
    }

    if (comb > max_comb) {
      max_comb = comb;
      target = i;
    }
  }

  printf("%d\n", target);

  return 0;
}
