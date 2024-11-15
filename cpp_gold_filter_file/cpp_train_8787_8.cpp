#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 50, kMaxM = 50, kInf = 0x3f3f3f3f;
const int kFx[4] = {-1, 1, 0, 0}, kFy[4] = {0, 0, -1, 1};
int n, m;
char buf[kMaxN][kMaxM + 1];
int dis[kMaxN][kMaxM];
bool vis[kMaxN][kMaxM];
queue<int> q;
bool InRange(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
void Bfs(int x, int y) {
  q.push(x * m + y);
  memset(dis, 0x3f, sizeof(dis));
  dis[x][y] = 0;
  vis[x][y] = true;
  while (q.size()) {
    x = q.front() / m;
    y = q.front() % m;
    vis[x][y] = false;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int nx = x + kFx[d], ny = y + kFy[d];
      if (InRange(nx, ny) &&
          dis[nx][ny] > dis[x][y] + (buf[x][y] != buf[nx][ny])) {
        dis[nx][ny] = dis[x][y] + (buf[x][y] != buf[nx][ny]);
        if (!vis[nx][ny]) {
          q.push(nx * m + ny);
          vis[nx][ny] = true;
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", buf[i]);
  int ans = kInf;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      Bfs(i, j);
      int step = -1;
      for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
          if (buf[x][y] == 'B') step = max(step, dis[x][y]);
      ++step;
      ans = min(ans, step);
    }
  printf("%d\n", ans);
  return 0;
}
