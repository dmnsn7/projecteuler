// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int multi_up = 1, multi_down = 1;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = 1; k <= 9; k++) {
        if ((10 * i + j) * k == (10 * j + k) * i && i < j) {
          multi_up *= i;
          multi_down *= k;
        }
      }
    }
  }

  printf("%d\n", multi_down / gcd(multi_up, multi_down));

  return 0;
}
