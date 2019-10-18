// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::to_string;

const int K = 6;

bool is_equal(int a, int b) {
  string sa = to_string(a);
  string sb = to_string(b);
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());

  return sa == sb;
}

int main() {
  int target;
  for (int i = 1;; i++) {
    bool flag = true;
    for (int j = K; j >= 2 && flag; j--) {
      flag = is_equal(i * j, i);
    }
    if (flag) {
      target = i;
      break;
    }
  }

  printf("%d\n", target);

  return 0;
}
