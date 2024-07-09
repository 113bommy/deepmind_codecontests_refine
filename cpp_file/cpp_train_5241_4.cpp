#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int i, n, m, s[2200][2200], a[2200][2200], j, numC, numS, num, Maxdis;
void read(int &x) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\r')
    ;
  x = c - 48;
}
void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n || !a[x][y]) return;
  a[x][y] = 0;
  num++;
  int dis = (x - i) * (x - i) + (y - j) * (y - j);
  if (dis > Maxdis) Maxdis = dis;
  dfs(x, y + 1);
  dfs(x, y - 1);
  dfs(x + 1, y);
  dfs(x - 1, y);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      read(a[i][j]);
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  int M = 5;
  for (i = 1; i <= n - M; ++i)
    for (j = 1; j <= n - M; ++j) {
      int num =
          s[i + M][j + M] - s[i + M][j - 1] - s[i - 1][j + M] + s[i - 1][j - 1];
      if (num >= (M + 1) * (M + 1) * 0.4)
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  for (i = 1; i <= n - M - 5; ++i)
    for (j = 1; j <= n - M - 5; ++j)
      if (a[i][j]) {
        num = 0;
        Maxdis = 0;
        dfs(i, j);
        if (num <= 25) continue;
        double O1 = Maxdis / 2, O2 = Maxdis * pi / 4;
        if (abs(O1 - num) < abs(O2 - num))
          numS++;
        else
          numC++;
      }
  printf("%d %d\n", numC, numS);
}
