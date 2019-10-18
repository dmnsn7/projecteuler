// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::string;
using std::to_string;
using std::vector;

const vector<vector<int> > PAIR = {{2, 3}, {1, 4}};

int pow(int a, int b) { return b ? a * pow(a, b - 1) : 1; }

int main() {
  set<int> pand;
  for (int i = 0; i < PAIR.size(); i++) {
    for (int j = pow(10, PAIR[i][0] - 1); j < pow(10, PAIR[i][0]); j++) {
      for (int k = pow(10, PAIR[i][1] - 1); k < pow(10, PAIR[i][1]); k++) {
        string join = to_string(j) + to_string(k) + to_string(j * k);
        if (join.length() == 9) {
          sort(join.begin(), join.end());
          if (unique(join.begin(), join.end()) == join.end() &&
              join[0] != '0') {
            pand.insert(j * k);
          }
        }
      }
    }
  }

  int sum = 0;
  for (set<int>::iterator it = pand.begin(); it != pand.end(); ++it) {
    sum += *it;
  }

  printf("%d\n", sum);

  return 0;
}
