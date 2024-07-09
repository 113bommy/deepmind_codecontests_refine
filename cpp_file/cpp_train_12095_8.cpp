#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int fw[N][N], fb[N][N];
int dx[8] = {-2, -2, 2, 2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
queue<pair<int, int> > q;
void bfs(int x, int y, int f[][N]) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) f[i][j] = -1;
  f[x][y] = 0;
  q.push(pair<int, int>(x, y));
  while (!q.empty()) {
    pair<int, int> h = q.front();
    q.pop();
    int x = h.first, y = h.second;
    for (int i = 0; i < 8; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
      if (f[xx][yy] == -1) {
        f[xx][yy] = f[x][y] + 1;
        q.push(pair<int, int>(xx, yy));
      }
    }
  }
}
void go(int x, int y, int f[][N]) {
  while (f[x][y]) {
    for (int i = 0; i < 8; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
      if (f[xx][yy] != -1 && f[xx][yy] < f[x][y]) {
        x = xx, y = yy;
        printf("%d %d\n", x, y);
        fflush(stdout);
        break;
      }
    }
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
