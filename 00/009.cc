// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const int SUM = 1000;

int main() {
  for (int i = 1; i <= SUM; i++) {
    for (int j = i; i + j <= SUM && SUM - i - j >= j; j++) {
      int k = SUM - i - j;
      if (i * i + j * j == k * k) {
        int multi = i * j * k;
        printf("%d\n", multi);
      }
    }
  }

  return 0;
}
