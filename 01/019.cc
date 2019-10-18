// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int YEAR_BEGIN = 1900;
const int YEAR_END = 2000;
const vector<int> MONTH_DAY = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool is_leap(int year) {
  return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int main() {
  int year = YEAR_BEGIN, month = 0, week = 1;
  int cnt = 0;
  while (year <= YEAR_END) {
    cnt += year >= YEAR_BEGIN + 1 && week == 0 ? 1 : 0;
    week = (week + MONTH_DAY[month] + (month == 1 && is_leap(year))) % 7;
    year += month == 11;
    month = month == 11 ? 0 : month + 1;
  }

  printf("%d\n", cnt);

  return 0;
}
