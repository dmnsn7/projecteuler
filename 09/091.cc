// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int N = 50;

int main() {
  int ans = 0;
  int x0 = 0, y0 = 0;
  for (int x1 = 0; x1 <= N; x1++) {
    for (int y1 = 0; y1 <= N; y1++) {
      for (int x2 = 0; x2 <= N; x2++) {
        for (int y2 = 0; y2 <= N; y2++) {
          if (x0 == x1 && y0 == y1) continue;
          if (x0 == x2 && y0 == y2) continue;
          if (x1 == x2 && y1 == y2) continue;
          int vx0 = x0 - x1, vy0 = y0 - y1;
          int vx1 = x0 - x2, vy1 = y0 - y2;
          int vx2 = x1 - x2, vy2 = y1 - y2;
          if (vx0 * vx1 + vy0 * vy1 == 0) {
            ans++;
          } else if (vx0 * vx2 + vy0 * vy2 == 0) {
            ans++;
          } else if (vx1 * vx2 + vy1 * vy2 == 0) {
            ans++;
          }
        }
      }
    }
  }

  printf("%d\n", ans / 2);
  return 0;
}
