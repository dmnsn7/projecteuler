// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

int get_acc(int n) {
  int ans = 0;
  for (int i = 1; i < 2 * n; i++) {
    int c = sqrt(n * n + i * i + 0.5);
    if (n * n + i * i == c * c) {
      if (i < n) {
        ans += i / 2;
      } else {
        ans += n - i + i / 2 + 1;
      }
    }
  }
  return ans;
}

int main() {
  int sum = 0, ans = 0;
  for (int i = 1; i <= 10000; i++) {
    sum += get_acc(i);
    if (sum > 1000000) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
