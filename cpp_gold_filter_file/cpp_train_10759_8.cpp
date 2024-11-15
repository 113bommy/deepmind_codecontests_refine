#include <bits/stdc++.h>
using namespace std;
const int maxint = 1000000022;
int a[15][15];
int d[15];
int u[2222];
int v[2222];
int w[2222];
int f[65555];
int n, m, s;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j) a[i][j] = maxint;
  int x, y, z;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    --x;
    --y;
    ++d[x];
    ++d[y];
    a[x][y] = min(a[x][y], z);
    a[y][x] = a[x][y];
    s += z;
    u[i] = x;
    v[i] = y;
    w[i] = z;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  for (int i = 0; i < m; ++i)
    if (a[0][u[i]] == maxint) {
      printf("-1\n");
      return 0;
    }
  for (int i = 1, j = 0; i < (1 << n); ++i) {
    f[i] = maxint;
    if (i == (1 << j + 1)) ++j;
    for (int k = 0; k < j; ++k)
      f[i] = min(f[i], f[i ^ (1 << j) ^ (1 << k)] + a[j][k]);
  }
  int step = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] & 1) step += (1 << i);
  if (f[step] == maxint)
    printf("-1\n");
  else
    printf("%d\n", f[step] + s);
  return 0;
}
