// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::string;
using std::vector;

int fac(int n) { return n ? fac(n - 1) * n : 1; }

const int N = 9;
const int M = 3;
const int K = fac(N + 1);
const vector<int> prime = {2, 3, 5, 7, 11, 13, 17};

int main() {
  string s;
  for (int i = 0; i <= N; i++) {
    s += i + '0';
  }

  int64_t sum = 0;
  for (int i = 0; i < K; i++) {
    next_permutation(s.begin(), s.end());
    if (s[0] == '0') {
      continue;
    }

    bool flag = true;
    int64_t num;
    for (int j = 0; j < prime.size() && flag; j++) {
      string ts = string(s.begin() + j + 1, s.begin() + j + M + 1);
      sscanf(ts.c_str(), "%ld", &num);
      if (num % prime[j] != 0) {
        flag = false;
      }
    }

    sscanf(s.c_str(), "%ld", &num);
    sum += flag ? num : 0;
  }

  printf("%ld\n", sum);

  return 0;
}
