// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::set;
using std::vector;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct Number {
  int o, p, q;
  Number() {}
  Number(int _o, int _p, int _q) { o = _o, p = _p, q = _q; }
  Number operator+(Number to) {
    if (o == 0 || to.o == 0) return Number(0, 0, 0);
    p *= o, o = 1;
    to.p *= to.o, to.o = 1;
    Number ret(1, p * to.p, q * to.p + p * to.q);
    if (ret.p < 0) ret.p *= -1, ret.o *= -1;
    if (ret.q < 0) ret.q *= -1, ret.o *= -1;
    int g = gcd(ret.p, ret.q);
    ret.p /= g, ret.q /= g;
    return ret;
  }
  Number operator-(Number to) { return *this + Number(-to.o, to.p, to.q); }
  Number operator*(Number to) {
    if (o == 0 || to.o == 0) return Number(0, 0, 0);
    Number ret(o * to.o, p * to.p, q * to.q);
    int g = gcd(ret.p, ret.q);
    ret.p /= g, ret.q /= g;
    return ret;
  }
  Number operator/(Number to) {
    if (o == 0 || to.o == 0 || to.q == 0) return Number(0, 0, 0);
    Number ret(o * to.o, p * to.q, q * to.p);
    int g = gcd(ret.p, ret.q);
    ret.p /= g, ret.q /= g;
    return ret;
  }
  bool operator<(const Number &to) const {
    if (o != to.o) return o < to.o;
    if (p != to.p) return p < to.p;
    return q < to.q;
  }
};

int get_val(set<Number> S) {
  int ans = 0;
  for (int i = 1;; i++) {
    if (S.find(Number(1, 1, i)) == S.end()) {
      break;
    } else {
      ans++;
    }
  }
  return ans;
}

set<Number> dfs(vector<Number> V) {
  set<Number> S;
  if (V.size() == 1) {
    S.insert(V[0]);
    return S;
  }
  for (int i = 0; i < V.size() - 1; i++) {
    vector<Number> tv = {V[i] + V[i + 1], V[i] - V[i + 1], V[i] * V[i + 1],
                         V[i] / V[i + 1]};
    for (int j = 0; j < tv.size(); j++) {
      vector<Number> VV;
      for (int k = 0; k < i; k++) {
        VV.push_back(V[k]);
      }
      VV.push_back(tv[j]);
      for (int k = i + 2; k < V.size(); k++) {
        VV.push_back(V[k]);
      }
      set<Number> ts = dfs(VV);
      for (set<Number>::iterator it = ts.begin(); it != ts.end(); ++it) {
        S.insert(*it);
      }
    }
  }
  return S;
}

set<Number> dfs_all(vector<int> numbers) {
  set<Number> ret;
  for (int i = 0; i < 24; i++) {
    next_permutation(numbers.begin(), numbers.end());
    set<Number> tmp =
        dfs(vector<Number>{Number(1, 1, numbers[0]), Number(1, 1, numbers[1]),
                           Number(1, 1, numbers[2]), Number(1, 1, numbers[3])});
    for (set<Number>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
      ret.insert(*it);
    }
  }

  return ret;
}

int main() {
  int max_val = 0, ans = 1234;
  for (int i = 1; i <= 9; i++) {
    for (int j = i + 1; j <= 9; j++) {
      for (int k = j + 1; k <= 9; k++) {
        for (int l = k + 1; l <= 9; l++) {
          set<Number> S = dfs_all(vector<int>{i, j, k, l});
          int val = get_val(S);
          if (val > max_val) {
            max_val = val;
            ans = i * 1000 + j * 100 + k * 10 + l;
          }
        }
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
