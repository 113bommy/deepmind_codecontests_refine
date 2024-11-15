#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
struct Edge {
  int to;
  int nxt;
} edge[MAXN << 1];
int n, id, root;
int v[MAXN];
int first[MAXN];
long long f[MAXN];
void addE(int u, int v) {
  edge[++id] = (Edge){v, first[u]};
  first[u] = id;
}
void dfs(int u, int fa) {
  vector<long long> nxt;
  for (int i = first[u]; i; i = edge[i].nxt)
    if (edge[i].to != fa) {
      v[edge[i].to]--;
      dfs(edge[i].to, u);
      nxt.push_back(f[edge[i].to]);
    }
  sort(nxt.begin(), nxt.end());
  for (int i = nxt.size() - 1; i >= max(0, (int)nxt.size() - v[u]); i--)
    f[u] += nxt[i] + 2;
  v[u] -= min(v[u], (int)nxt.size());
  for (int i = first[u]; i; i = edge[i].nxt)
    if (edge[i].to != fa) {
      f[u] += min(v[u], v[edge[i].to]);
      v[u] -= min(v[u], v[edge[i].to]);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int u, v, i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    addE(u, v);
    addE(v, u);
  }
  scanf("%d", &root);
  dfs(root, 0);
  printf("%I64d\n", f[root]);
  return 0;
}
