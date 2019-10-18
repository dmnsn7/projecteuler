// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;

const int N = 28123;

int get_fac_sum(int n) {
  int fac_sum = 1, tn = n;
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      int to_multi = 1, base = 1;
      while (n % i == 0) {
        base *= i;
        to_multi += base;
        n /= i;
      }

      fac_sum *= to_multi;
    }
  }

  if (n != 1) {
    fac_sum *= (n + 1);
  }

  return fac_sum - tn;
}

bool is_abund(int n) { return get_fac_sum(n) > n; }

int main() {
  set<int> abund;
  for (int i = 1; i <= N; i++) {
    if (is_abund(i)) {
      abund.insert(i);
    }
  }

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    bool flag = true;
    for (set<int>::iterator it = abund.begin();
         it != abund.end() && *it <= i - *it && flag; ++it) {
      if (abund.find(i - *it) != abund.end()) {
        flag = false;
      }
    }

    sum += flag ? i : 0;
  }

  printf("%d\n", sum);

  return 0;
}
