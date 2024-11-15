#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pp = pair<pair<int, int>, int>;
const int maxn = 2e5 + 5, maxk = 18;
int n, q;
vector<int> adj[maxn];
int depth[maxn];
int par[maxk][maxn];
int tin[maxn], tout[maxn], t = 1;
void dfs(int i, int p) {
  tin[i] = t++;
  depth[i] = depth[p] + 1;
  par[0][i] = p;
  for (int k = 1; k < maxk; k++) {
    par[k][i] = par[k - 1][par[k - 1][i]];
  }
  for (int j : adj[i]) {
    if (j == p) continue;
    dfs(j, i);
  }
  tout[i] = t - 1;
}
int lca(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  for (int k = maxk - 1; k >= 0; k--) {
    int bb = par[k][b];
    if (depth[bb] >= depth[a]) b = bb;
  }
  if (a == b) return a;
  for (int k = maxk - 1; k >= 0; k--) {
    int aa = par[k][a];
    int bb = par[k][b];
    if (aa != bb) {
      a = aa;
      b = bb;
    }
  }
  return par[0][a];
}
int dis(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
vector<pair<int, int>> graph[maxn];
pair<int, int> dist[maxn];
void solve(vector<pair<int, int>> virus, vector<int> special) {
  vector<int> sp;
  for (auto p : virus) sp.push_back(p.first);
  for (auto i : special) sp.push_back(i);
  sort(sp.begin(), sp.end(), [](int a, int b) { return tin[a] < tin[b]; });
  sp.erase(unique(sp.begin(), sp.end()), sp.end());
  int nn = sp.size();
  for (int i = 1; i < nn; i++) {
    sp.push_back(lca(sp[i - 1], sp[i]));
  }
  sort(sp.begin(), sp.end(), [](int a, int b) { return tin[a] < tin[b]; });
  sp.erase(unique(sp.begin(), sp.end()), sp.end());
  for (auto i : sp) {
    graph[i].clear();
  }
  stack<int> st;
  for (auto i : sp) {
    while (!st.empty() && tin[i] > tout[st.top()]) {
      st.pop();
    }
    if (!st.empty()) {
      int len = depth[i] - depth[st.top()];
      graph[st.top()].push_back({i, len});
      graph[i].push_back({st.top(), len});
    }
    st.push(i);
  }
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  for (auto i : sp) dist[i] = {maxn, -1};
  for (int i = 0; i < virus.size(); i++) {
    pq.push(make_pair(make_pair(0, i), virus[i].first));
    dist[virus[i].first] = {0, i};
  }
  while (!pq.empty()) {
    int u = pq.top().second;
    int s = virus[dist[u].second].second;
    int source = virus[dist[u].second].first;
    pq.pop();
    for (auto e : graph[u]) {
      int v = e.first;
      int nt = (dis(source, v) + s - 1) / s;
      if (dist[v] > make_pair(nt, dist[u].second)) {
        dist[v] = make_pair(nt, dist[u].second);
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  for (auto i : special) {
    cout << dist[i].second << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector<pair<int, int>> virus;
    vector<int> special;
    while (k--) {
      int v, s;
      cin >> v >> s;
      virus.push_back({v, s});
    }
    while (m--) {
      int v;
      cin >> v;
      special.push_back(v);
    }
    solve(virus, special);
  }
}
