// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::vector;

int main() {
  vector<int> cnt(1000001, 0);
  for (int i = 1; i <= 250000; i++) {
    for (int j = i + 2; j * j - i * i <= 1000000; j += 2) {
      cnt[j * j - i * i]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 1000000; i++) {
    if (cnt[i] >= 1 && cnt[i] <= 10) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
