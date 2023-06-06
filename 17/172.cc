// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::min;
using std::vector;

const int DIGITS = 17;
vector<long long> f;
vector<vector<int>> vp;
vector<int> p;
int pos = 0;
int sum = 0;

void dfs() {
  if (sum == DIGITS) {
    vp.push_back(p);
    return;
  }
  if (pos > 9) {
    return;
  }
  for (int i = 0; i <= min(DIGITS - sum, pos == 1 ? 2 : 3); i++) {
    pos++;
    sum += i;
    p.push_back(i);
    dfs();
    p.pop_back();
    sum -= i;
    pos--;
  }
}

int main() {
  for (int i = 0; i <= DIGITS; i++) {
    f.push_back(i == 0 ? 1 : f[i - 1] * i);
  }

  dfs();

  long long ans = 0;
  for (int i = 0; i < vp.size(); i++) {
    long long add = f[DIGITS];
    for (int j = 0; j < vp[i].size(); j++) {
      add /= f[vp[i][j]];
    }
    ans += add;
  }
  printf("%ld\n", ans * 9);

  return 0;
}
