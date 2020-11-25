// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::map;
using std::set;
using std::sort;
using std::string;
using std::to_string;
using std::vector;

string get_mapped(string s) {
  string to;
  map<char, char> M;
  char c = '0';
  for (int i = 0; i < s.size(); i++) {
    if (M.find(s[i]) != M.end()) {
      to += M[s[i]];
    } else if (c == '9') {
      return string("");
    } else {
      to += M[s[i]] = c++;
    }
  }
  return to;
}

int main() {
  char word[16];
  vector<string> W;
  while (scanf("%*[\",]%15[A-Z]", word) == 1) {
    string mapped = get_mapped(string(word));
    if (mapped.length()) {
      W.push_back(string(word));
    }
  }

  set<string> S;
  set<string> S2;
  for (int i = 0; i < W.size(); i++) {
    for (int j = i + 1; j < W.size(); j++) {
      string sa = W[i], sb = W[j];
      sort(sa.begin(), sa.end());
      sort(sb.begin(), sb.end());
      if (sa == sb) {
        S.insert(get_mapped(sa));
        S2.insert(get_mapped(W[i] + W[j]));
        S2.insert(get_mapped(W[j] + W[i]));
      }
    }
  }

  int64_t ans = 0;
  map<string, vector<int64_t>> M;
  for (int i = 1; i < 1000000; i++) {
    string s = to_string(static_cast<int64_t>(i) * i), ss = s;
    sort(ss.begin(), ss.end());
    string mapped = get_mapped(ss);
    for (int j = 0; j < M[mapped].size(); j++) {
      string comb =
          to_string(static_cast<int64_t>(i) * i) + to_string(M[mapped][j]);
      if (S2.find(get_mapped(comb)) != S2.end()) {
        ans = static_cast<int64_t>(i) * i;
      }
    }
    if (S.find(get_mapped(s)) != S.end()) {
      M[mapped].push_back(static_cast<int64_t>(i) * i);
    }
  }

  printf("%ld\n", ans);
  return 0;
}
