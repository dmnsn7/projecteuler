// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int get_score(int n) {
  if (n <= 60) {
    return (n + 2) / 3 * (3 - (60 - n) % 3);
  }
  return n == 61 ? 25 : 50;
}

int main() {
  int ans = 21;
  for (int i = 1; i <= 62; i++) {
    for (int j = 2; j <= 62; j += 3) {
      if (get_score(i) + get_score(j) < 100) {
        ans++;
      }
    }
  }
  for (int i = 1; i <= 62; i++) {
    for (int j = i; j <= 62; j++) {
      for (int k = 2; k <= 62; k += 3) {
        if (get_score(i) + get_score(j) + get_score(k) < 100) {
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
