// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::vector;

const int N = 1000;

const vector<string> ZERO_TO_NINETEEN = {
    "",        "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

const vector<string> ZERO_TO_NINETY = {
    "",      "",      "twenty",  "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety",
};

const char HUNDRED[] = "hundred";
const char AND[] = "and";
const char THOUSAND[] = "thousand";

int get_cnt(int n) {
  if (n <= 19) {
    return ZERO_TO_NINETEEN[n].length();
  } else if (n <= 99) {
    return ZERO_TO_NINETY[n / 10].length() + ZERO_TO_NINETEEN[n % 10].length();
  } else if (n <= 999) {
    return ZERO_TO_NINETEEN[n / 100].length() + strlen(HUNDRED) +
           (n % 100 == 0 ? 0 : strlen(AND) + get_cnt(n % 100));
  } else {
    return ZERO_TO_NINETEEN[1].length() + strlen(THOUSAND);
  }
}

int main() {
  int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    sum += get_cnt(i);
  }

  printf("%d\n", sum);

  return 0;
}
