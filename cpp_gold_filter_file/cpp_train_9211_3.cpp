#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y;
} edges[200200];
struct abcd {
  int to, next;
} table[200200 << 1];
int head[200200], tot = 1;
int n, m, q, cnt;
int belong[200200], dpt[200200], fa[200200][18];
int mark1[200200], mark2[200200];
void Add(int x, int y) {
  table[++tot].to = y;
  table[tot].next = head[x];
  head[x] = tot;
}
void Tarjan(int x, int from) {
  static int dpt[200200], low[200200], T;
  static int stack[200200], top;
  int i;
  dpt[x] = low[x] = ++T;
  stack[++top] = x;
  for (i = head[x]; i; i = table[i].next)
    if (i ^ from ^ 1) {
      if (dpt[table[i].to])
        low[x] = min(low[x], dpt[table[i].to]);
      else
        Tarjan(table[i].to, i), low[x] = min(low[x], low[table[i].to]);
    }
  if (dpt[x] == low[x]) {
    int t;
    ++cnt;
    do {
      t = stack[top--];
      belong[t] = cnt;
    } while (t != x);
  }
}
namespace Union_Find_Set {
int fa[200200], rank[200200];
int Find(int x) {
  if (!fa[x] || fa[x] == x) return fa[x] = x;
  return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;
  if (rank[x] > rank[y]) swap(x, y);
  if (rank[x] == rank[y]) ++rank[y];
  fa[x] = y;
}
}  // namespace Union_Find_Set
void DFS1(int x) {
  int i;
  dpt[x] = dpt[fa[x][0]] + 1;
  for (i = 1; i <= 17; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (i = head[x]; i; i = table[i].next)
    if (table[i].to != fa[x][0]) {
      fa[table[i].to][0] = x;
      DFS1(table[i].to);
    }
}
int LCA(int x, int y) {
  int j;
  if (dpt[x] < dpt[y]) swap(x, y);
  for (j = 17; ~j; j--)
    if (dpt[fa[x][j]] >= dpt[y]) x = fa[x][j];
  if (x == y) return x;
  for (j = 17; ~j; j--)
    if (fa[x][j] != fa[y][j]) x = fa[x][j], y = fa[y][j];
  return fa[x][0];
}
void DFS2(int x) {
  int i;
  for (i = head[x]; i; i = table[i].next)
    if (table[i].to != fa[x][0]) {
      DFS2(table[i].to);
      mark1[x] += mark1[table[i].to];
      mark2[x] += mark2[table[i].to];
    }
  if (mark1[x] && mark2[x]) exit((puts("No"), 0));
}
int main() {
  using namespace Union_Find_Set;
  int i, x, y;
  cin >> n >> m >> q;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    edges[i].x = x;
    edges[i].y = y;
    Add(x, y);
    Add(y, x);
  }
  for (i = 1; i <= n; i++)
    if (!belong[i]) Tarjan(i, 0);
  memset(head, 0, sizeof head);
  tot = 0;
  for (i = 1; i <= m; i++) {
    x = belong[edges[i].x];
    y = belong[edges[i].y];
    if (x != y) Add(x, y), Add(y, x), Union(x, y);
  }
  for (i = 1; i <= cnt; i++)
    if (i == Find(i)) DFS1(i);
  for (i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    x = belong[x];
    y = belong[y];
    if (Find(x) != Find(y)) return puts("No"), 0;
    int lca = LCA(x, y);
    mark1[x]++;
    mark2[y]++;
    mark1[lca]--;
    mark2[lca]--;
  }
  for (i = 1; i <= cnt; i++)
    if (i == Find(i)) DFS2(i);
  puts("Yes");
  return 0;
}
