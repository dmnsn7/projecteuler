// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;

const int L = 3;
const int R = 1000;

int main() {
  int ans = 0;
  for (int i = L; i <= R; i++) {
    int a = i - 1, b = i + 1, max_r = 2 * i;
    while (true) {
      int ta = a * (i - 1) % (i * i);
      int tb = b * (i + 1) % (i * i);
      if (ta == i - 1 && tb == i + 1) {
        break;
      }
      max_r = max(max_r, (ta + tb) % (i * i));
      a = ta, b = tb;
    }
    ans += max_r;
  }

  printf("%d\n", ans);
  return 0;
}
