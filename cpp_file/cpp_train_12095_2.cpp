#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int mov[8][2] = {{2, 1},  {2, -1},  {1, 2},  {1, -2},
                       {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int n, m;
int fw[N][N], fb[N][N];
void bfs(int sx, int sy, int f[][N]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = -1;
    }
  }
  int x, y, nx, ny;
  queue<pair<int, int>> Q;
  f[sx][sy] = 0;
  Q.push({sx, sy});
  while (!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for (int k = 0; k < 8; k++) {
      nx = x + mov[k][0], ny = y + mov[k][1];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (f[nx][ny] == -1) {
        f[nx][ny] = f[x][y] + 1;
        Q.push({nx, ny});
      }
    }
  }
}
void go(int x, int y, int f[][N]) {
  int nx, ny;
  while (f[x][y]) {
    for (int k = 0; k < 8; k++) {
      nx = x + mov[k][0], ny = y + mov[k][1];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (f[nx][ny] >= 0 && f[nx][ny] < f[x][y]) {
        x = nx;
        y = ny;
        break;
      }
    }
    printf("%d %d\n", x, y);
  }
}
int main() {
  int xw, yw, xb, yb, hn, hm;
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &xw, &yw, &xb, &yb);
  hn = n >> 1, hm = m >> 1;
  bfs(hn, hm, fw);
  bfs(hn + 1, hm, fb);
  double tw = fw[xw][yw];
  double tb = fb[xb][yb] + 0.5;
  double twb = fb[xw][yw];
  double tbb = fw[xb][yb] + 0.5;
  if (((xw + yw) & 1) ^ ((xb + yb) & 1)) {
    if (tw < tb) {
      puts("WHITE");
      go(xw, yw, fw);
    } else if (twb < tb + 1) {
      puts("WHITE");
      go(xw, yw, fb);
      go(hn + 1, hm, fw);
    } else {
      puts("BLACK");
      go(xb, yb, fb);
    }
  } else {
    if (tb < tw) {
      puts("BLACK");
      go(xb, yb, fb);
    } else if (tbb < tw + 1) {
      puts("BLACK");
      go(xb, yb, fw);
      go(hn, hm, fb);
    } else {
      puts("WHITE");
      go(xw, yw, fw);
    }
  }
  return 0;
}
