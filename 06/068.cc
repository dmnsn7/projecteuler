// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::max;
using std::vector;

int main() {
  vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int64_t ans = 0;
  for (int i = 0; i < 3628800; i++) {
    next_permutation(V.begin(), V.end());
    int sum = V[0] + V[1] + V[5];
    if (V[1] + V[2] + V[6] != sum) continue;
    if (V[2] + V[3] + V[7] != sum) continue;
    if (V[3] + V[4] + V[8] != sum) continue;
    if (V[4] + V[0] + V[9] != sum) continue;
    if (V[0] == 10) continue;
    if (V[1] == 10) continue;
    if (V[2] == 10) continue;
    if (V[3] == 10) continue;
    if (V[4] == 10) continue;
    if (V[5] > V[6]) continue;
    if (V[5] > V[7]) continue;
    if (V[5] > V[8]) continue;
    if (V[5] > V[9]) continue;
    char s[17];
    snprintf(s, sizeof(s), "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", V[5], V[0], V[1],
             V[6], V[1], V[2], V[7], V[2], V[3], V[8], V[3], V[4], V[9], V[4],
             V[0]);
    int64_t tans;
    sscanf(s, "%ld", &tans);
    ans = max(ans, tans);
  }

  printf("%ld\n", ans);
  return 0;
}
