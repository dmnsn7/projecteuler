// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::cin;

char G[10][10];

bool dfs(int r, int c) {
  if (r == 9 && c == 0) return true;
  if (G[r][c] != '0') {
    return dfs(c == 8 ? r + 1 : r, c == 8 ? 0 : c + 1);
  }
  for (int i = 1; i <= 9; i++) {
    int flag = 0;
    for (int j = 0; j < 9; j++) {
      if (G[j][c] == i + '0') {
        flag = 1;
        break;
      }
      if (G[r][j] == i + '0') {
        flag = 1;
        break;
      }
      if (G[r / 3 * 3 + j / 3][c / 3 * 3 + j % 3] == i + '0') {
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    G[r][c] = i + '0';
    if (dfs(c == 8 ? r + 1 : r, c == 8 ? 0 : c + 1)) {
      return true;
    }
    G[r][c] = '0';
  }
  return false;
}

int main() {
  int t = 50, ans = 0;
  while (t--) {
    scanf("%*s%*s");
    for (int i = 0; i < 9; i++) {
      cin >> G[i];
    }
    dfs(0, 0);
    ans += 100 * (G[0][0] - '0') + 10 * (G[0][1] - '0') + (G[0][2] - '0');
  }

  printf("%d\n", ans);
  return 0;
}
