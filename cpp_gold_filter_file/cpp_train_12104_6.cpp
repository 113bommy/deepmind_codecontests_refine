#include <bits/stdc++.h>
using namespace std;
int f[21][21][21][21];
char a[21][21];
char b[41][41];
int n, m, d;
int sg1, sg2;
int fb(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
  bool mark[401];
  memset(mark, 0, sizeof(mark));
  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++)
      if (b[i][j] == 'R')
        mark[fb(x1, y1, x2, j - 1) ^ fb(x1, j + 1, x2, y2)] = true;
      else if (b[i][j] == 'L')
        mark[fb(x1, y1, i - 1, y2) ^ fb(i + 1, y1, x2, y2)] = true;
      else if (b[i][j] == 'X')
        mark[fb(x1, y1, i - 1, j - 1) ^ fb(x1, j + 1, i - 1, y2) ^
             fb(i + 1, y1, x2, j - 1) ^ fb(i + 1, j + 1, x2, y2)] = true;
  for (int i = 0; i <= 400; i++)
    if (!mark[i]) {
      f[x1][y1][x2][y2] = i;
      break;
    }
  return f[x1][y1][x2][y2];
}
void solvew() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if ((i + j) % 2 == 0) b[(i + j) / 2][(i - j + d + 1) / 2] = a[i][j];
  memset(f, -1, sizeof(f));
  sg1 = fb(1, 1, d, d);
}
void solveb() {
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if ((i + j) % 2 == 1) b[(i + j) / 2][(i - j + d + 1) / 2] = a[i][j];
  memset(f, -1, sizeof(f));
  sg2 = fb(1, 1, d, d);
}
int main() {
  scanf("%d%d", &n, &m);
  d = max(n, m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  solvew();
  solveb();
  if (sg1 ^ sg2)
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
