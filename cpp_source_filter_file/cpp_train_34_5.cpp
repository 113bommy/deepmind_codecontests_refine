#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int N, C, cnt, d[maxn], q[maxn], head[maxn], d1[maxn], d2[maxn];
double ans;
struct Data {
  int next, to;
} data[maxn << 1];
bool vis[maxn];
void add(int x, int y) {
  data[++cnt] = (Data){head[x], y};
  head[x] = cnt;
}
void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x]; i; i = data[i].next) {
    Data &e = data[i];
    if (vis[e.to]) continue;
    d2[e.to] = d2[x] + 1;
    if (!d1[e.to])
      d1[e.to] = d1[x] + 1, ans += 1.0 / d1[e.to];
    else
      ans += 1.0 / d2[e.to] - 2.0 / (d1[e.to] + d2[e.to] + C - 2);
    dfs(e.to);
  }
  vis[x] = 0;
}
int main() {
  scanf("%d", &N);
  for (int i = 1, u, v; i <= N; ++i)
    scanf("%d%d", &u, &v), ++u, ++v, ++d[u], ++d[v], add(u, v), add(v, u);
  int h = 1, t = 0;
  for (int i = 1; i <= N; ++i)
    if (d[i] == 1) q[++t] = i;
  while (h <= t)
    for (int i = head[q[h++]]; i; i = data[i].next)
      if (!(--d[data[i].to])) q[++t] = data[i].to;
  C = N - t;
  for (int i = 1; i <= N; ++i) {
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    d1[i] = d2[i] = 1, dfs(i);
  }
  printf("%.10lf\n", ans + N);
  return 0;
}
