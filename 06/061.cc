// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::vector;

const int N = 6;
const int LOW = 1000;
const int HIGH = 10000;
const int K = 1 * 2 * 3 * 4 * 5;

vector<int> V[N];
vector<int> mir = {0, 1, 2, 3, 4, 5};
vector<int> q;
int sum = 0;

int get_value(int n, int type) {
  if (type == 0) {
    return n * (n + 1) / 2;
  } else if (type == 1) {
    return n * n;
  } else if (type == 2) {
    return n * (3 * n - 1) / 2;
  } else if (type == 3) {
    return n * (2 * n - 1);
  } else if (type == 4) {
    return n * (5 * n - 3) / 2;
  } else {
    return n * (3 * n - 2);
  }
}

bool is_inter(int a, int b) { return a % 100 == b / 100; }

void dfs() {
  int sz = q.size();
  if (sz == N) {
    if (is_inter(q.back(), q[0])) {
      for (int i = 0; i < q.size(); i++) {
        sum += q[i];
      }
    }
    return;
  }

  for (int i = 0; i < V[mir[sz]].size(); i++) {
    if (sz == 0 || is_inter(q.back(), V[mir[sz]][i])) {
      q.push_back(V[mir[sz]][i]);
      dfs();
      q.pop_back();
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 1;; j++) {
      int num = get_value(j, i);
      if (num >= LOW && num < HIGH) {
        V[i].push_back(num);
      } else if (num >= HIGH) {
        break;
      }
    }
  }

  for (int i = 0; i < K; i++) {
    dfs();
    next_permutation(mir.begin(), mir.end());
  }

  printf("%d\n", sum);

  return 0;
}
