#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;
const int maxn = (int)1e5 + 10;
vector<int> ed[maxn];
vector<int> we[maxn];
int sz[maxn];
void dfs(int v, int p = -1) {
  sz[v] = 1;
  for (int u : ed[v]) {
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
  }
}
int cm[maxn];
vector<int> g[maxn];
void build(int v, int p, int c) {
  cm[v] = c;
  g[c].push_back(v);
  for (int u : ed[v]) {
    if (u != p) {
      build(u, v, c);
    }
  }
}
int h[maxn], c[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    x--;
    y--;
    ed[x].push_back(y);
    ed[y].push_back(x);
    we[x].push_back(w);
    we[y].push_back(w);
  }
  if (n == 1) {
    cout << 0 << '\n';
    cout << 1 << '\n';
    return 0;
  }
  dfs(0);
  int v = 0;
  while (true) {
    bool ok = true;
    for (int u : ed[v]) {
      if (2 * sz[u] >= n && sz[u] < sz[v]) {
        v = u;
        ok = false;
        break;
      }
    }
    if (ok) {
      break;
    }
  }
  dfs(v);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)ed[i].size(); j++) {
      int u = ed[i][j];
      if (sz[u] < sz[i]) {
        res += (long long)2 * we[i][j] * min(sz[u], (n - sz[u]));
      }
    }
  }
  cout << res << '\n';
  int posit = 0;
  for (int u : ed[v]) {
    build(u, v, posit++);
  }
  cm[v] = posit;
  g[posit].push_back(v);
  posit++;
  set<int> el;
  for (int i = 0; i < posit; i++) {
    sort((g[i]).begin(), (g[i]).end());
    reverse((g[i]).begin(), (g[i]).end());
    el.insert(g[i].back());
  }
  set<pair<int, int> > s;
  for (int i = 0; i < posit; i++) {
    h[i] = c[i] = (int)g[i].size();
    if (i == posit - 1) {
      h[i] = c[i] = -10000;
    }
    s.insert(make_pair(h[i] + c[i], i));
  }
  int root = v;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int wh = cm[i];
    if (s.rbegin()->first != n - i || wh == s.rbegin()->second) {
      int v = *el.begin();
      el.erase(v);
      if (c[v] != c[i] || (i == root && wh != s.rbegin()->second)) {
        s.erase(make_pair(h[wh] + c[wh], wh));
        c[wh]--;
        s.insert(make_pair(h[wh] + c[wh], wh));
        wh = cm[v];
        s.erase(make_pair(h[wh] + c[wh], wh));
        h[wh]--;
        s.insert(make_pair(h[wh] + c[wh], wh));
        g[wh].pop_back();
        if (!g[wh].empty()) {
          el.insert(g[wh].back());
        }
        ans.push_back(v);
      } else {
        int u = *el.begin();
        el.erase(u);
        el.insert(v);
        v = u;
        s.erase(make_pair(h[wh] + c[wh], wh));
        c[wh]--;
        s.insert(make_pair(h[wh] + c[wh], wh));
        wh = cm[v];
        s.erase(make_pair(h[wh] + c[wh], wh));
        h[wh]--;
        s.insert(make_pair(h[wh] + c[wh], wh));
        g[wh].pop_back();
        if (!g[wh].empty()) {
          el.insert(g[wh].back());
        }
        ans.push_back(v);
      }
    } else {
      int v = g[s.rbegin()->second].back();
      el.erase(v);
      s.erase(make_pair(h[wh] + c[wh], wh));
      c[wh]--;
      s.insert(make_pair(h[wh] + c[wh], wh));
      wh = cm[v];
      s.erase(make_pair(h[wh] + c[wh], wh));
      h[wh]--;
      s.insert(make_pair(h[wh] + c[wh], wh));
      g[wh].pop_back();
      if (!g[wh].empty()) {
        el.insert(g[wh].back());
      }
      ans.push_back(v);
    }
  }
  for (int x : ans) {
    printf("%d ", x + 1);
  }
}
