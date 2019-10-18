// Copyright [2017] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::cin;
using std::string;

bool is_triangle(int n) {
  int num = sqrt(n * 2);
  return num * (num + 1) == n * 2;
}

int main() {
  string text;
  cin >> text;

  int cnt = 0;
  string word;
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == '\"' && word != string("")) {
      int score = 0;
      for (int j = 0; j < word.length(); j++) {
        score += word[j] - 'A' + 1;
      }
      cnt += is_triangle(score) ? 1 : 0;

      word = "";
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      word += text[i];
    }
  }

  printf("%d\n", cnt);

  return 0;
}
