// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::vector;

int min_sum = 1e9;
int cur_sum = 0;
vector<int> v, ans;

void dfs() {
  vector<int> s(1 << v.size(), 0);
  vector<int> b(1 << v.size(), 0);
  for (int i = 1; i < 1 << v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (i & (1 << j)) {
        s[i] += v[j];
        b[i]++;
      }
    }
  }
  for (int i = 1; i < 1 << v.size(); i++) {
    for (int j = i + 1; j < 1 << v.size(); j++) {
      if (i & j) {
        continue;
      }
      if (b[i] == b[j] && s[i] == s[j]) {
        return;
      }
      if (b[i] > b[j] && s[i] <= s[j]) {
        return;
      }
      if (b[i] < b[j] && s[i] >= s[j]) {
        return;
      }
    }
  }
  if (v.size() == 7) {
    if (cur_sum < min_sum) {
      min_sum = cur_sum;
      ans = v;
      return;
    }
  }
  int l = v.size() == 0 ? 20 : v.back() + 1;
  for (int i = l; i <= 50; i++) {
    v.push_back(i);
    cur_sum += i;
    dfs();
    cur_sum -= i;
    v.pop_back();
  }
}

int main() {
  dfs();
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
  }
  putchar('\n');
  return 0;
}
