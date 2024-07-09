#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m, u, v, K, N;
int id[MAXN];
bool visited[MAXN];
int f[MAXN][18];
int depth[MAXN];
vector<int> e[MAXN];
vector<int> de[MAXN];
struct Conn {
  int n;
  int low[MAXN], dfn[MAXN];
  vector<int>* e;
  vector<pair<int, int> > keyEdge;
  void dfs(int u, int fa) {
    low[u] = dfn[u];
    for (vector<int>::const_iterator i = e[u].begin(); i != e[u].end(); ++i) {
      if (dfn[*i] == -1) {
        dfn[*i] = dfn[u] + 1;
        dfs(*i, u);
        if (low[*i] > dfn[u]) {
          keyEdge.push_back(make_pair(u, *i));
        }
        low[u] = min(low[u], low[*i]);
      } else if (*i != fa) {
        low[u] = min(low[u], low[*i]);
      }
    }
  }
  void gao() {
    memset(dfn, -1, sizeof(dfn));
    for (int i = 0; i < n; ++i) {
      if (dfn[i] == -1) {
        dfn[i] = 0;
        dfs(i, -1);
      }
    }
  }
} conn;
void dfs(int u) {
  for (vector<int>::const_iterator i = e[u].begin(); i != e[u].end(); ++i) {
    if (*i != -1 && !visited[*i]) {
      visited[*i] = true;
      id[*i] = N;
      dfs(*i);
    }
  }
}
void dfs(int u, int fa) {
  if (fa == -1) {
    for (int i = 0; i < 18; ++i) {
      f[u][i] = u;
    }
    depth[u] = 0;
  } else {
    f[u][0] = fa;
    for (int i = 1; i < 18; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
    }
    depth[u] = depth[fa] + 1;
  }
  for (vector<int>::const_iterator i = e[u].begin(); i != e[u].end(); ++i) {
    if (*i != fa) {
      dfs(*i, u);
    }
  }
}
inline int goUp(int u, int lvl) {
  for (int i = 0; i < 18; ++i) {
    if ((lvl & 1 << i) != 0) {
      u = f[u][i];
    }
  }
  return u;
}
inline int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  u = goUp(u, depth[u] - depth[v]);
  if (u == v) {
    return u;
  }
  for (int i = 17; i >= 0; --i) {
    int nu = goUp(u, i);
    int nv = goUp(v, i);
    if (nu != nv) {
      u = nu;
      v = nv;
    }
  }
  return f[u][0];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    e[u - 1].push_back(v - 1);
    e[v - 1].push_back(u - 1);
  }
  conn.n = n;
  conn.e = e;
  conn.gao();
  for (int i = 0; i < n; ++i) {
    sort(e[i].begin(), e[i].end());
  }
  for (vector<pair<int, int> >::const_iterator i = conn.keyEdge.begin();
       i != conn.keyEdge.end(); ++i) {
    u = i->first;
    v = i->second;
    de[u].push_back(lower_bound(e[u].begin(), e[u].end(), v) - e[u].begin());
    de[v].push_back(lower_bound(e[v].begin(), e[v].end(), u) - e[v].begin());
  }
  for (int i = 0; i < n; ++i) {
    for (vector<int>::const_iterator j = de[i].begin(); j != de[i].end(); ++j) {
      e[i][*j] = -1;
    }
  }
  N = 0;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
      id[i] = N++;
    }
  }
  for (int i = 0; i < n; ++i) {
    e[i].clear();
  }
  for (vector<pair<int, int> >::const_iterator i = conn.keyEdge.begin();
       i != conn.keyEdge.end(); ++i) {
    u = i->first;
    v = i->second;
    e[id[u]].push_back(id[v]);
    e[id[v]].push_back(id[u]);
  }
  dfs(0, -1);
  scanf("%d", &K);
  for (int i = 0; i < K; ++i) {
    scanf("%d%d", &u, &v);
    u = id[u - 1];
    v = id[v - 1];
    int p = lca(u, v);
    printf("%d\n", depth[u] + depth[v] - depth[p] * 2);
  }
  return 0;
}
