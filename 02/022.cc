// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::cin;
using std::string;
using std::vector;

int main() {
  string text;
  cin >> text;

  vector<string> names;
  string name;
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == '\"' && name != string("")) {
      names.push_back(name);
      name = "";
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      name += text[i];
    }
  }

  sort(names.begin(), names.end());
  int score_sum = 0;
  for (int i = 0; i < names.size(); i++) {
    for (int j = 0; j < names[i].length(); j++) {
      score_sum += (names[i][j] - 'A' + 1) * (i + 1);
    }
  }

  printf("%d\n", score_sum);

  return 0;
}
