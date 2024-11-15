#include <bits/stdc++.h>
using namespace std;
int n, tot;
struct Point {
  int head, f[20], d, sum;
} p[100007];
struct Edge {
  int next, node;
} e[100007 << 1];
void Add(int x, int y) {
  e[++tot].next = p[x].head;
  p[x].head = tot;
  e[tot].node = y;
}
void Dfs(int x) {
  p[x].sum = 1;
  for (int i = p[x].head; i; i = e[i].next) {
    int y = e[i].node;
    if (!p[y].d) {
      p[y].f[0] = x;
      for (int j = 1; j <= 19; j++) p[y].f[j] = p[p[y].f[j - 1]].f[j - 1];
      p[y].d = p[x].d + 1;
      Dfs(y);
      p[x].sum += p[y].sum;
    }
  }
}
int Up(int x, int d) {
  for (int i = 19; i >= 0; i--)
    if (p[p[x].f[i]].d >= d) x = p[x].f[i];
  return x;
}
int LCA(int x, int y) {
  x = Up(x, p[y].d);
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (p[x].f[i] != p[y].f[i]) x = p[x].f[i], y = p[y].f[i];
  return p[x].f[0];
}
int main() {
  int x, y, q;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    Add(x, y), Add(y, x);
  }
  p[1].d = 1;
  Dfs(1);
  scanf("%d", &q);
  while (q--) {
    int tt;
    scanf("%d%d", &x, &y);
    if (x == y) {
      printf("1\n");
      continue;
    }
    if (p[x].d < p[y].d) tt = x, x = y, y = tt;
    int lca = LCA(x, y);
    int ll = -p[lca].d + p[x].d - p[lca].d + p[y].d;
    if (ll & 1)
      puts("0");
    else {
      int cc = Up(x, p[x].d - ll / 2);
      if (cc == lca) {
        int ux = Up(x, p[lca].d + 1), uy = Up(y, p[lca].d + 1);
        printf("%d\n", n - p[ux].sum - p[uy].sum);
      } else {
        int ux = Up(x, p[cc].d + 1);
        printf("%d\n", p[cc].sum - p[ux].sum);
      }
    }
  }
}
