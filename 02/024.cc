// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 10;
const int K = 1000000;

vector<int> kth_permutation(int n, int k) {
  vector<int> fac(n, 1);
  for (int i = 1; i < n; i++) {
    fac[i] = fac[i - 1] * i;
  }

  vector<int> permutation;
  vector<int> is_used(n, 0);
  for (int i = 0; i < n; i++) {
    int kth = k / fac[n - i - 1];
    k %= fac[n - i - 1];
    for (int j = 0, cnt = 0; j < n; j++) {
      cnt += !is_used[j];
      if (cnt == kth + 1) {
        permutation.push_back(j);
        is_used[j] = 1;
        break;
      }
    }
  }

  return permutation;
}

int main() {
  vector<int> permutation = kth_permutation(N, K - 1);

  for (int i = 0; i < permutation.size(); i++) {
    putchar(permutation[i] + '0');
    if (i == permutation.size() - 1) {
      putchar('\n');
    }
  }

  return 0;
}
