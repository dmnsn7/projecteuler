// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 1000000;
vector<int> fac(10, 0);
vector<int> loop_size(N, 0);

int get_fac(int n) {
  return fac[n] ? fac[n] : (n == 0 ? 1 : n * get_fac(n - 1));
}

int get_sum(int n) {
  int ans = 0;
  while (n) {
    ans += get_fac(n % 10);
    n /= 10;
  }
  return ans;
}

int get_loop_size(int n) {
  if (n >= N) return get_loop_size(get_sum(n)) + 1;

  if (loop_size[n] == -1) return 0;

  if (loop_size[n]) return loop_size[n];

  loop_size[n] = -1;

  return loop_size[n] = get_loop_size(get_sum(n)) + 1;
}

int main() {
  int ans = 0;
  for (int i = 3; i < N; i++) {
    if (get_loop_size(i) == 60) {
      ans += 1;
    }
  }

  printf("%d\n", ans);
  return 0;
}
