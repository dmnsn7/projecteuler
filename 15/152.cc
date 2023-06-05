// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

vector<int> v;
int magic = 1073217600ll;  // (8*9*5*7*13)^2;
int ans = 0, up = magic / 2, left = 0;

void dfs() {
  if (up == 0) {
    ans++;
    return;
  }

  if (left < up) {
    return;
  }

  int cur = v.back();
  if (up >= magic / cur / cur) {
    up -= magic / cur / cur;
    left -= magic / cur / cur;
    v.pop_back();
    dfs();
    v.push_back(cur);
    left += magic / cur / cur;
    up += magic / cur / cur;
  }

  left -= magic / cur / cur;
  v.pop_back();
  dfs();
  v.push_back(cur);
  left += magic / cur / cur;
}

int main() {
  for (int i = 80; i >= 2; i--) {
    if (8 * 9 * 5 * 7 * 13 % i == 0) {
      left += magic / i / i;
      v.push_back(i);
    }
  }

  dfs();

  printf("%d\n", ans);

  return 0;
}
