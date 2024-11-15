#include <bits/stdc++.h>
using namespace std;
const int maxn = 52;
static char S[maxn][maxn];
static int dis[maxn][maxn], n, m;
static int h[maxn * maxn * 10][2], lh;
static bool vis[maxn][maxn];
void update(int x, int y, int d, char ch) {
  if (x <= 0 || y <= 0 || x > n || y > m) return;
  if (ch != S[x][y]) d++;
  if (dis[x][y] > d) {
    dis[x][y] = d;
    if (vis[x][y] == false) {
      vis[x][y] = true;
      h[++lh][0] = x;
      h[lh][1] = y;
    }
  }
}
int Sol(int Sx, int Sy) {
  memset(dis, 10, sizeof(dis));
  dis[Sx][Sy] = 0;
  int t = 1;
  h[1][0] = Sx;
  h[1][1] = Sy;
  lh = 1;
  while (t <= lh) {
    int x = h[t][0], y = h[t][1];
    update(x - 1, y, dis[x][y], S[x][y]);
    update(x + 1, y, dis[x][y], S[x][y]);
    update(x, y - 1, dis[x][y], S[x][y]);
    update(x, y + 1, dis[x][y], S[x][y]);
    vis[x][y] = false;
    t++;
  }
  int d = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (d < dis[i][j] && S[i][j] == 'B') d = dis[i][j];
  return d;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) S[i][j] = getchar();
    scanf("\n");
  }
  int ans = n * m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans = min(ans, Sol(i, j));
  printf("%d\n", ans + 1);
  return 0;
}
