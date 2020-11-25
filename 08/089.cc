// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::cin;
using std::string;

const int N = 1000;

int main() {
  string s;
  int ans = 0;
  while (cin >> s) {
    if (s.find("VIIII") != string::npos)
      ans += 3;
    else if (s.find("IIII") != string::npos)
      ans += 2;
    if (s.find("LXXXX") != string::npos)
      ans += 3;
    else if (s.find("XXXX") != string::npos)
      ans += 2;
    if (s.find("DCCCC") != string::npos)
      ans += 3;
    else if (s.find("CCCC") != string::npos)
      ans += 2;
  }

  printf("%d\n", ans);
  return 0;
}
