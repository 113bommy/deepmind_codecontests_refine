#include <bits/stdc++.h>
using namespace std;
int R, C;
char bd[352][353];
int N, w[350 * 350];
int M, v[350 * 350];
bool Try(int x, int y) {
  N = 0;
  w[N++] = x << 9 | y;
  bd[x][y] = '0';
  for (int* h = w; h < w + N; ++h) {
    x = *h >> 9;
    y = *h & 511;
    for (int k = 0; k < 9; ++k) {
      int x1 = k / 3 - 1, y1 = k % 3 - 1;
      x1 += x;
      y1 += y;
      if (bd[x1][y1] == '1') {
        w[N++] = x1 << 9 | y1;
        bd[x1][y1] = '0';
      }
    }
  }
  if (N % 4) return false;
  sort(w, w + N);
  int dd = 0;
  if (w[1] == w[0] + 1) {
    dd = 0;
  } else {
    dd = 1;
  }
  x = w[0] >> 9;
  y = w[0] & 511;
  M = 0;
  const int mv[2][4][2] = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}},
                           {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}}};
  for (int d = 0; d < 4; ++d) {
    for (int i = 0; i < N / 4; ++i) {
      v[M++] = x << 9 | y;
      x += mv[dd][d][0];
      y += mv[dd][d][1];
      if (x < 1 || x > R || y < 1 || y > C) return false;
    }
  }
  sort(v, v + M);
  for (int i = 0; i < N; ++i)
    if (v[i] != w[i]) return false;
  return true;
}
int main() {
  int TT;
  scanf("%d", &TT);
  for (int TTT = 1; TTT <= TT; ++TTT) {
    scanf("%d%d", &R, &C);
    for (int i = 0; i <= R + 1; i += R + 1) fill(bd[i], bd[i] + C + 2, '0');
    for (int i = 1; i <= R; ++i) {
      bd[i][0] = '0';
      scanf("%s", bd[i] + 1);
      bd[i][C + 1] = '0';
    }
    int ans = 0;
    for (int i = 1; i <= R; ++i)
      for (int j = 1; j <= C; ++j)
        if (bd[i][j] == '1') ans += Try(i, j) ? 1 : 0;
    cout << ans << endl;
  }
  return 0;
}
