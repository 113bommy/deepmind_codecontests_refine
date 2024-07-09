#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
}
int n, m, a[2000][2000], b[2000][2000], id[2000][2000], cnt, ans[10000];
int dis[2000][2000], vst[2000][2000], lv;
int qx[4000000], qy[4000000];
void bfs(int x, int y) {
  id[x][y] = cnt;
  qx[1] = x, qy[1] = y;
  int L(0), R(1);
  while (L++ != R) {
    for (int i = (qx[L] - 1); i <= (qx[L] + 1); ++i)
      for (int j = (qy[L] - 1); j <= (qy[L] + 1); ++j)
        if (!id[i][j] && a[i][j]) {
          id[i][j] = cnt;
          qx[++R] = i, qy[R] = j;
        }
  }
}
int cal(int x, int y) {
  vst[x][y] = ++lv;
  dis[x][y] = 0;
  qx[1] = x, qy[1] = y;
  int L(0), R(1);
  while (L++ != R) {
    for (int i = (qx[L] - 1); i <= (qx[L] + 1); ++i)
      for (int j = (qy[L] - 1); j <= (qy[L] + 1); ++j)
        if (vst[i][j] != lv && a[i][j]) {
          vst[i][j] = lv;
          dis[i][j] = dis[qx[L]][qy[L]] + 1;
          if (dis[i][j] > 4) return R;
          qx[++R] = i, qy[R] = j;
        }
  }
  return R;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (m); ++j) read(b[i][j]);
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (m); ++j) {
      a[i][j] = 1;
      for (int ii = (i - 1); ii <= (i + 1); ++ii)
        for (int jj = (j - 1); jj <= (j + 1); ++jj)
          if (!b[ii][jj]) a[i][j] = 0;
    }
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (m); ++j)
      if (!id[i][j] && a[i][j]) {
        ++cnt;
        bfs(i, j);
      }
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (m); ++j) {
      b[i][j] = a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1];
      if (a[i - 1][j - 1] && !a[i][j - 1] && !a[i - 1][j]) ++b[i][j];
      if (a[i + 1][j - 1] && !a[i][j - 1] && !a[i + 1][j]) ++b[i][j];
      if (a[i - 1][j + 1] && !a[i][j + 1] && !a[i - 1][j]) ++b[i][j];
      if (a[i + 1][j + 1] && !a[i][j + 1] && !a[i + 1][j]) ++b[i][j];
    }
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (m); ++j)
      if (a[i][j] && b[i][j] == 1) {
        if (cal(i, j) < 20) ++ans[id[i][j]];
      }
  sort(ans + 1, ans + cnt + 1);
  printf("%d\n", cnt);
  for (int i = 1; i <= (cnt - 1); ++i) printf("%d ", ans[i]);
  printf("%d\n", ans[cnt]);
  return 0;
}
