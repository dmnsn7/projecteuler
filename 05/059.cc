// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

const char KEY[] = "god";

int main() {
  int num, idx = 0;
  int sum = 0;
  while (~scanf("%d,", &num)) {
    sum += num ^ KEY[idx++ % 3];
  }

  printf("%d\n", sum);

  return 0;
}
