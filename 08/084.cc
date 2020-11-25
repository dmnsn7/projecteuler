// Copyright [2020] <dmnsn7@gmail.com>

#include <bits/stdc++.h>

using std::make_pair;
using std::min;
using std::pair;
using std::vector;

const int N = 4;

int get_next_r(int pos) {
  if (pos == 7) {
    return 15;
  } else if (pos == 22) {
    return 25;
  }
  return 5;
}

int get_next_u(int pos) {
  if (pos == 7) {
    return 12;
  } else if (pos == 22) {
    return 28;
  }
  return 12;
}

vector<vector<double>> matrix_multiply(vector<vector<double>> A,
                                       vector<vector<double>> B) {
  vector<vector<double>> C(40, vector<double>(40, 0));
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 40; j++) {
      for (int k = 0; k < 40; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main() {
  vector<vector<double>> T(40, vector<double>(40, 0));
  for (int i = 0; i < 40; i++) {
    if (i == 30) continue;
    for (int j = 2; j <= 2 * N; j++) {
      double p = (min(j, N * 2 + 2 - j) - 1.0) / N / N;
      int k = (i + j) % 40;
      if (k == 30) {
        T[i][10] += p;
      } else if (k == 2 || k == 17 || k == 33) {
        T[i][k] += p * 14 / 16;
        T[i][0] += p / 16;
        T[i][10] += p / 16;
      } else if (k == 7 || k == 22 || k == 36) {
        T[i][k] += p * 6 / 16;
        T[i][0] += p / 16;
        T[i][10] += p / 16;
        T[i][11] += p / 16;
        T[i][24] += p / 16;
        T[i][39] += p / 16;
        T[i][5] += p / 16;
        T[i][get_next_r(k)] += p * 2 / 16;
        T[i][get_next_u(k)] += p / 16;
        T[i][k - 3] += p / 16;
      } else {
        T[i][k] += p;
      }
    }
  }
  for (int i = 0; i < 20; i++) {
    T = matrix_multiply(T, T);
  }
  vector<pair<double, int>> V;
  for (int i = 0; i < 40; i++) {
    V.push_back(make_pair(T[0][i], i));
  }
  sort(V.begin(), V.end());
  printf("%02d%02d%02d\n", V[39].second, V[38].second, V[37].second);

  return 0;
}
