// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

int isp(int64_t n) {
  for (int64_t i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<int64_t> v = {1, 2, 8};
  int64_t a = 19, b = 20, delta = 18;
  int64_t a1 = 11, a2 = 17, a3 = 17, b1 = 19, b2 = 17, b3 = 41;
  while (true) {
    if (isp(a1) && isp(a2) && isp(a3)) {
      v.push_back(a);
    }
    if (isp(b1) && isp(b2) && isp(b3)) {
      v.push_back(b);
    }
    if (v.size() >= 2000) {
      break;
    }
    a += delta;
    b += delta;
    a1 += 6, a2 += 12, a3 += 6;
    b1 += 6, b2 += 6, b3 += 12;
    delta += 6;
  }
  printf("%ld\n", v[1999]);
  return 0;
}
