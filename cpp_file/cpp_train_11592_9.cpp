#include <bits/stdc++.h>
bool o = true;
int w[16], c[16], a[4][4], n, s, m, i, t, j;
void dfs2(int x, int y) {
  if (y == 2) {
    if (a[x][0] + a[x][1] != s) return;
    ++x;
    y = 0;
    if (x == 2) {
      if (a[0][0] + a[1][1] == s) o = 0;
      return;
    }
  }
  if (x == 1 && y == 1) {
    if (a[0][1] + a[1][0] != s) return;
  }
  for (int i = 0; i < m && o; ++i)
    if (c[i]) {
      a[x][y] = w[i];
      c[i]--;
      if (x != 1)
        dfs2(x, y + 1);
      else if (w[i] + a[0][y] == s)
        dfs2(x, y + 1);
      ++c[i];
    }
}
void dfs3(int x, int y) {
  if (y == 3) {
    if (a[x][0] + a[x][1] + a[x][2] != s) return;
    ++x;
    y = 0;
    if (x == 3) {
      if (a[0][0] + a[1][1] + a[2][2] == s) o = 0;
      return;
    }
  }
  if (x == 2 && y == 1) {
    if (a[0][2] + a[1][1] + a[2][0] != s) return;
  }
  for (int i = 0; i < m && o; ++i)
    if (c[i]) {
      a[x][y] = w[i];
      c[i]--;
      if (x != 2)
        dfs3(x, y + 1);
      else if (w[i] + a[0][y] + a[1][y] == s)
        dfs3(x, y + 1);
      ++c[i];
    }
}
void dfs4(int x, int y) {
  if (y == 4) {
    if (a[x][0] + a[x][1] + a[x][2] + a[x][3] != s) return;
    ++x;
    y = 0;
    if (x == 4) {
      if (a[0][0] + a[1][1] + a[2][2] + a[3][3] == s) o = 0;
      return;
    }
  }
  if (x == 3 && y == 1) {
    if (a[0][3] + a[1][2] + a[2][1] + a[3][0] != s) return;
  }
  for (int i = 0; i < m && o; ++i)
    if (c[i]) {
      a[x][y] = w[i];
      c[i]--;
      if (x != 3)
        dfs3(x, y + 1);
      else if (w[i] + a[0][y] + a[1][y] == s)
        dfs4(x, y + 1);
      ++c[i];
    }
}
int main() {
  scanf("%d", &n);
  for (i = s = 0; i < n * n; ++i) {
    scanf("%d", &t);
    s += t;
    for (j = 0; j < m; ++j)
      if (w[j] == t) {
        ++c[j];
        t = 1 << 30;
      }
    if (t != 1 << 30) {
      w[m] = t;
      c[m++] = 1;
    }
  }
  printf("%d\n", s /= n);
  if (n == 1) return printf("%d\n", w[0]), 0;
  if (n == 2) dfs2(0, 0);
  if (n == 3) dfs3(0, 0);
  if (n == 4) dfs4(0, 0);
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) printf("%d ", a[i][j]);
}
