#include <bits/stdc++.h>
using namespace std;
int n, m, len, dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char d[17][17];
bool vis[17][17][1 << 16];
struct node {
  int x, y, sta, step;
} seg[12];
int f_dir(node a, node b) {
  if (a.x == b.x)
    return a.y > b.y ? 0 : 1;
  else
    return a.x > b.x ? 2 : 3;
}
int test(node a, node b) {
  if (a.x < 1 || a.x > n || a.y < 1 || a.y > m || d[a.x][a.y] == '#' ||
      vis[a.x][a.y][a.sta])
    return 0;
  node tmp = b;
  for (int i = 1; i < len - 1; i++) {
    int sta = (b.sta >> (len * 2 - i * 2 - 2)) & 3;
    if (sta == 0)
      b.y--;
    else if (sta == 1)
      b.y++;
    else if (sta == 2)
      b.x--;
    else if (sta == 3)
      b.x++;
    if (a.x == b.x && a.y == b.y) return 0;
  }
  return 1;
}
int bfs() {
  queue<node> Q;
  int sta = 0;
  for (int i = 2; i <= len; i++) {
    int tmp = f_dir(seg[i - 1], seg[i]);
    sta = (sta << 2) | tmp;
  }
  seg[1].sta = sta;
  seg[1].step = 0;
  Q.push(seg[1]);
  while (!Q.empty()) {
    node now = Q.front();
    Q.pop();
    node next;
    for (int i = 0; i < 4; i++) {
      next.x = now.x + dir[i][0];
      next.y = now.y + dir[i][1];
      int tt = f_dir(next, now);
      next.sta = (now.sta >> 2) | (tt << (len * 2 - 4));
      next.step = now.step + 1;
      int t = test(next, now);
      if (!t) continue;
      vis[next.x][next.y][next.sta] = 1;
      if (d[next.x][next.y] == '@') return next.step;
      Q.push(next);
    }
  }
  return -1;
}
int main() {
  scanf("%d%d", &n, &m);
  len = 0;
  for (int i = 1; i <= n; i++) scanf("%s", d[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (d[i][j] > '0' && d[i][j] <= '9') {
        len = max(len, d[i][j] - '0');
        seg[d[i][j] - '0'].x = i;
        seg[d[i][j] - '0'].y = j;
      }
    }
  }
  printf("%d\n", bfs());
  return 0;
}
