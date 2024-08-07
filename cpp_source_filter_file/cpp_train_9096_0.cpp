#include <bits/stdc++.h>
using namespace std;
const int N = 10005, inf = (int)1e9;
struct _three {
  int a, b, c;
} edge[N * 8];
int n, m, g, s, t, ans, tot;
int v[N], st[N + N], qu[N + N], dis[N + N];
void Link(int x, int y, int z) {
  edge[++tot] = (_three){y, st[x], z};
  st[x] = tot;
  edge[++tot] = (_three){x, st[y], z};
  st[y] = tot;
}
void Init() {
  scanf("%d%d%d", &n, &m, &g);
  for (int i = 1; i <= n; i++) scanf("%d", v + i);
  int x;
  tot = 1;
  s = n + m + 1;
  t = s + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (v[i])
      Link(s, i, x);
    else
      Link(i, t, x);
  }
  int sex, wei, k;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &sex, &wei, &k);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &x);
      if (sex)
        Link(i + n, x, inf);
      else
        Link(x, i + n, inf);
    }
    scanf("%d", &x);
    ans += wei;
    if (x) wei += g;
    if (sex)
      Link(s, i + n, wei);
    else
      Link(i + n, t, wei);
  }
}
void bfs() {
  int be = 0, en = 1;
  qu[1] = s;
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  while (be < en) {
    int x = qu[++be];
    for (int i = st[x]; i; i = edge[i].b)
      if (edge[i].c && dis[edge[i].a] == -1) {
        dis[edge[i].a] = dis[x] + 1;
        qu[++en] = edge[i].a;
      }
  }
}
int Aug(int x, int flow) {
  int ret = 0;
  if (x == t) return flow;
  for (int i = st[x]; i; i = edge[i].b)
    if (edge[i].c && dis[edge[i].a] == dis[x] + 1) {
      int t1 = min(edge[i].c, flow), temp = Aug(edge[i].a, t1);
      if (temp < t1) dis[edge[i].a] = -1;
      edge[i].c -= temp;
      edge[i ^ 1].c += temp;
      ret += temp;
      flow -= temp;
      if (!flow) break;
    }
  return ret;
}
void Work() {
  while (1) {
    bfs();
    if (dis[t] == -1) break;
    ans -= Aug(s, inf);
  }
  printf("%d\n", ans);
}
int main() {
  Init();
  Work();
  return 0;
}
