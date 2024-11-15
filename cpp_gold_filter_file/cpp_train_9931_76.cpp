#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, f, ii, jj, fnd, cnt, cc, tt;
int qq[20000];
int q[2000][2000];
int g[2000][2000];
int w[2000][2000];
int ff[2000][2000];
int c1, c2;
void dfs(int x, int y) {
  if (w[x][y] != 0) return;
  w[x][y] = f;
  if (q[x][y - 1] == 1) dfs(x, y - 1);
  if (q[x][y + 1] == 1) dfs(x, y + 1);
  if (q[x - 1][y] == 1) dfs(x - 1, y);
  if (q[x + 1][y] == 1) dfs(x + 1, y);
}
void go(int x, int y) {
  if (ff[x][y] != 0) return;
  ff[x][y] = 1;
  if (q[x][y - 1] == 1)
    if (g[x][y - 1] == 0) go(x, y - 1);
  if (q[x][y + 1] == 1)
    if (g[x][y + 1] == 0) go(x, y + 1);
  if (q[x - 1][y] == 1)
    if (g[x - 1][y] == 0) go(x - 1, y);
  if (q[x + 1][y] == 1)
    if (g[x + 1][y] == 0) go(x + 1, y);
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> q[i][j];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if ((q[i][j] == 1) && (w[i][j] == 0)) {
        f++;
        dfs(i, j);
      }
  int Q = 6;
  for (i = 1; i <= n - Q; i++)
    for (j = 1; j <= m - Q; j++) {
      fnd = 0;
      cnt = 0;
      cc = 0;
      c1 = c2 = 0;
      for (ii = i; ii <= i + Q; ii++)
        for (jj = j; jj <= j + Q; jj++) {
          if (w[ii][jj]) cc = w[ii][jj];
          if (q[ii][jj] == 1)
            c1++;
          else
            c2++;
        }
      if (c1 > c2 * 3) {
        for (ii = i; ii <= i + Q; ii++)
          for (jj = j; jj <= j + Q; jj++) {
            if (q[ii][jj] == 1) g[ii][jj] = 1;
          }
      }
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (q[i][j] == 1)
        if (g[i][j] == 0)
          if (ff[i][j] == 0) {
            qq[w[i][j]]++;
            go(i, j);
          }
    }
  cout << f << endl;
  sort(qq + 1, qq + 1 + f);
  for (i = 1; i < f; i++) cout << qq[i] << " ";
  cout << qq[f] << endl;
  return 0;
}
