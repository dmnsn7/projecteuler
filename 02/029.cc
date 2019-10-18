// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::make_pair;
using std::pair;
using std::set;

const int A = 100;
const int B = 100;

int main() {
  set<pair<int, int> > is_visited;
  int cnt = (A - 1) * (B - 1);
  for (int i = 2; i <= A; i++) {
    for (int j = 2; j <= B; j++) {
      int ti = i, min_div = 1;
      for (int k = 2; k <= ti / k; k++) {
        if (ti % k == 0) {
          min_div *= k;
          while (ti % k == 0) {
            ti /= k;
          }
        }
      }

      int tti = i, level = 0;
      while (min_div != 1 && tti % min_div == 0) {
        tti /= min_div;
        level++;
      }

      if (tti != 1) {
        is_visited.insert(make_pair(i, j));
      } else if (is_visited.find(make_pair(min_div, level * j)) ==
                 is_visited.end()) {
        is_visited.insert(make_pair(min_div, level * j));
      } else {
        cnt--;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}
