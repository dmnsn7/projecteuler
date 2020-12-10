// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::to_string;

int64_t ans = 0;

int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;

int cur_len = 0;

int64_t multiplier = 1;

void dfs() {
  if (cnt_0 > 0 && cnt_1 > 0 && cnt_2 > 0) {
    for (int64_t j = cur_len, base = 1; j <= 16; j++, base *= 16) {
      ans += multiplier * base;
    }
    return;
  }
  if (cur_len == 16) {
    return;
  }
  for (int i = cur_len ? 0 : 1; i < 4; i++) {
    if (i == 0) {
      cur_len++;
      cnt_0++;
      dfs();
      cnt_0--;
      cur_len--;
    } else if (i == 1) {
      cur_len++;
      cnt_1++;
      dfs();
      cnt_1--;
      cur_len--;
    } else if (i == 2) {
      cur_len++;
      cnt_2++;
      dfs();
      cnt_2--;
      cur_len--;
    } else if (i == 3) {
      cur_len++;
      multiplier *= 13;
      dfs();
      multiplier /= 13;
      cur_len--;
    }
  }
}

string to_bit(int n) {
  if (n < 10) {
    return to_string(n);
  } else if (n == 10) {
    return string("A");
  } else if (n == 11) {
    return string("B");
  } else if (n == 12) {
    return string("C");
  } else if (n == 13) {
    return string("D");
  } else if (n == 14) {
    return string("E");
  }
  return string("F");
}

string to_hex(int64_t n) {
  string s;
  while (n) {
    s = to_bit(n % 16) + s;
    n /= 16;
  }
  return s;
}

int main() {
  dfs();
  printf("%s\n", to_hex(ans).c_str());
  return 0;
}
