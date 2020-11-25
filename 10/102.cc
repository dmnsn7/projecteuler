// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int main() {
  int ans = 0;
  int x0, y0, x1, y1, x2, y2;
  while (~scanf("%d,%d,%d,%d,%d,%d", &x0, &y0, &x1, &y1, &x2, &y2)) {
    int dx0 = x1 - x0, dy0 = y1 - y0;
    int dx1 = x2 - x0, dy1 = y2 - y0;
    int s0 = abs(x0 * y1 - x1 * y0);
    int s1 = abs(x0 * y2 - x2 * y0);
    int s2 = abs(x1 * y2 - x2 * y1);
    int s3 = abs(dx0 * dy1 - dx1 * dy0);
    if (s0 + s1 + s2 == s3) {
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
