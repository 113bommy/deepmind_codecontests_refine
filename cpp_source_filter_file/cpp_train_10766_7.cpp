#include <bits/stdc++.h>
using namespace std;
char s[75][75];
struct point {
  int e[3];
  int v(int i) { return e[(i + 3) % 3]; }
};
struct path {
  int u, v;
} pre[75][75][75];
int dis[75][75][75], n;
bool check(point ft, point tp) {
  sort(ft.e, ft.e + 3);
  sort(tp.e, tp.e + 3);
  if (dis[tp.e[0]][tp.e[1]][tp.e[2]] > dis[ft.e[0]][ft.e[1]][ft.e[2]]) {
    dis[tp.e[0]][tp.e[1]][tp.e[2]] = dis[ft.e[0]][ft.e[1]][ft.e[2]] + 1;
    return true;
  }
  return false;
}
bool isSame(point a, point b) {
  sort(a.e, a.e + 3);
  sort(b.e, b.e + 3);
  for (int i = 0; i < 3; i++) {
    if (a.e[i] != b.e[i]) return false;
  }
  return true;
}
void bfs(point T) {
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++) dis[i][j][k] = 0x3fffffff;
  point ft, tp;
  for (i = 0; i < 3; i++) ft.e[i] = i;
  queue<point> q;
  q.push(ft);
  dis[0][1][2] = 0;
  while (!q.empty()) {
    ft = q.front();
    if (isSame(ft, T)) {
      int a = T.e[0], b = T.e[1], c = T.e[2];
      printf("%d\n", k = dis[a][b][c]);
      a = ft.e[0], b = ft.e[1], c = ft.e[2];
      for (i = 0; i < k; i++) {
        int u = pre[a][b][c].u, v = pre[a][b][c].v;
        printf("%d %d\n", u + 1, v + 1);
        if (a == v)
          a = u;
        else if (b == v)
          b = u;
        else
          c = u;
      }
      return;
    }
    q.pop();
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        if (ft.e[j] == i) break;
      }
      if (j < 3) continue;
      for (j = 0; j < 3; j++) {
        if (s[ft.v(j)][i] == s[ft.v(j + 1)][ft.v(j + 2)]) {
          tp = ft;
          tp.e[j] = i;
          if (check(ft, tp)) {
            pre[tp.e[0]][tp.e[1]][tp.e[2]].u = ft.e[j];
            pre[tp.e[0]][tp.e[1]][tp.e[2]].v = tp.e[j];
            q.push(tp);
          }
        }
      }
    }
  }
  puts("-1");
}
int main() {
  point p;
  int i, j;
  while (~scanf("%d", &n)) {
    for (i = 0; i < 3; i++) {
      scanf("%d", &p.e[i]);
      --p.e[i];
    }
    sort(p.e, p.e + 3);
    for (i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    bfs(p);
  }
  return 0;
}
