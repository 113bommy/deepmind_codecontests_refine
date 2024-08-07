#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, w, i;
};
Edge make_edge(int v, int w, int i) {
  Edge out;
  out.v = v;
  out.w = w;
  out.i = i;
  return out;
}
const int N = 2e5 + 100;
const int INF = 2 * 1e9;
map<int, int> m;
vector<Edge> adj[N];
map<int, int>::iterator it;
int dis[N], a[N], b[N], c[N], p[N], e[N], par[N];
set<pair<int, int> > st;
bool flag[N];
vector<int> ans;
void dijkstra(int x, int n) {
  for (int i = 0; i < n; i++) {
    par[i] = -1;
    e[i] = -1;
    dis[i] = INF;
  }
  dis[x] = 0;
  st.insert(make_pair(dis[x], x));
  while (!st.empty()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (int i = 0; i < adj[v].size(); i++) {
      int u = adj[v][i].v;
      int w = adj[v][i].w;
      int ind = adj[v][i].i;
      if (dis[v] + w < dis[u]) {
        st.erase(make_pair(dis[u], u));
        dis[u] = dis[v] + w;
        e[u] = ind;
        par[u] = v;
        st.insert(make_pair(dis[u], u));
      }
    }
  }
  return;
}
int main() {
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    int X, D, T, P;
    cin >> X >> D >> T >> P;
    if (X - P >= 0) {
      m[X - P] = 1;
      m[X + D] = 1;
      a[i] = X - P;
      b[i] = X + D;
      c[i] = T + P;
    } else
      flag[i] = 1;
  }
  m[0] = 1;
  m[l] = 1;
  int cnt = 0;
  for (it = m.begin(); it != m.end(); it++, cnt++) {
    it->second = cnt;
    p[cnt] = it->first;
  }
  for (int i = 0; i + 1 < cnt; i++) {
    adj[m[p[i]]].push_back(make_edge(m[p[i + 1]], p[i + 1] - p[i], -1));
    adj[m[p[i + 1]]].push_back(make_edge(m[p[i]], p[i + 1] - p[i], -1));
  }
  for (int i = 0; i < n; i++)
    if (!flag[i]) adj[m[a[i]]].push_back(make_edge(m[b[i]], c[i], i));
  dijkstra(0, cnt);
  cout << dis[cnt - 1] << "\n";
  int x = cnt - 1;
  while (x != -1) {
    if (e[x] != -1) ans.push_back(e[x] + 1);
    x = par[x];
  }
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
