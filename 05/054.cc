// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::cin;
using std::map;
using std::max;
using std::string;
using std::vector;

const int N = 1000;
const char VALUE[] = "23456789TJQKA";
const char SUIT[] = "CDHS";

int value_to_int(char c) {
  int ans;
  for (int i = 0; i < strlen(VALUE); i++) {
    if (VALUE[i] == c) {
      ans = i;
      break;
    }
  }

  return ans;
}

int suit_to_int(char c) {
  int ans;
  for (int i = 0; i < strlen(SUIT); i++) {
    if (SUIT[i] == c) {
      ans = i;
      break;
    }
  }

  return ans;
}

int get_bit_cnt(int n) {
  int cnt = 0;
  while (n) {
    cnt += n % 2;
    n >>= 1;
  }

  return cnt;
}

int get_rank(map<int, int> m) {
  int distinct = m.size();
  int max_diff = m.rbegin()->first - m.begin()->first;
  int color = 0, max_cnt = 0;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    int c = it->second;
    max_cnt = max(max_cnt, get_bit_cnt(c));
    color |= c;
  }

  int ans;
  if (get_bit_cnt(color) == 1 && distinct == 5 && max_diff == 4) {
    ans = 0;
  } else if (max_cnt == 4) {
    ans = 1;
  } else if (distinct == 2) {
    ans = 2;
  } else if (get_bit_cnt(color) == 1) {
    ans = 3;
  } else if (distinct == 5 && max_diff == 4) {
    ans = 4;
  } else if (max_cnt == 3) {
    ans = 5;
  } else if (distinct == 3) {
    ans = 6;
  } else if (max_cnt == 2) {
    ans = 7;
  } else {
    ans = 8;
  }

  return ans;
}

vector<int> get_sorted(map<int, int> m) {
  map<int, vector<int>> l;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
    int value = it->first;
    int cnt = get_bit_cnt(it->second);
    l[cnt].push_back(value);
  }

  vector<int> sorted;
  for (map<int, vector<int>>::reverse_iterator it = l.rbegin(); it != l.rend();
       ++it) {
    int cnt = it->first;
    vector<int> v = it->second;
    for (int i = v.size() - 1; i >= 0; i--) {
      for (int j = 0; j < cnt; j++) {
        sorted.push_back(v[i]);
      }
    }
  }

  return sorted;
}

bool is_greater(vector<int> a, vector<int> b) {
  bool ans = false;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      ans = a[i] > b[i];
      break;
    }
  }

  return ans;
}

int main() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    map<int, int> p1, p2;
    for (int j = 0; j < 10; j++) {
      string s;
      cin >> s;
      int value = value_to_int(s[0]);
      int suit = suit_to_int(s[1]);
      if (j < 5) {
        p1[value] |= 1 << suit;
      } else {
        p2[value] |= 1 << suit;
      }
    }
    if (get_rank(p1) < get_rank(p2)) {
      cnt++;
    } else if (get_rank(p1) == get_rank(p2)) {
      vector<int> pp1 = get_sorted(p1);
      vector<int> pp2 = get_sorted(p2);
      cnt += is_greater(pp1, pp2);
    }
  }

  printf("%d\n", cnt);

  return 0;
}
