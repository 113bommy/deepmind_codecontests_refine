#include <bits/stdc++.h>
int szx, szy;
using namespace std;
class MatchingGraph {
 public:
  int n, res;
  vector<vector<int> > graph;
  vector<bool> vis;
  bool dfs(int v) {
    vis[v] = true;
    for (int i = 0; i < (int)graph[v].size(); i++) {
      int nx = graph[v][i];
      if (match[nx] == -1 || (!vis[match[nx]] && dfs(match[nx]))) {
        match[v] = nx;
        match[nx] = v;
        return true;
      }
    }
    return false;
  }
  bool matching() {
    for (int i = 0; i < n; i++) vis[i] = false;
    bool changed = false;
    for (int i = 0; i < n; i++)
      if (match[i] == -1 && !vis[i] && dfs(i)) {
        res++;
        changed = true;
      }
    return changed;
  }
  vector<int> match;
  MatchingGraph(int n) : n(n), res(0) {
    vis = vector<bool>(n);
    match = vector<int>(n);
    graph = vector<vector<int> >(n);
    for (int i = 0; i < n; i++) match[i] = -1;
  }
  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int max_matching() {
    while (matching())
      ;
    return res;
  }
};
int n;
map<int, vector<int> > mx, my;
struct line {
  int sx, sy, ex, ey;
};
vector<line> ansx, ansy;
line joinx[1001], joiny[1001];
bool chx[1001], chy[1001];
bool cant[1001][1001];
bool vis[2001];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    mx[x].push_back(y);
    my[y].push_back(x);
  }
  for (auto cur : mx) {
    auto v = cur.second;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
      line newi = {cur.first, v[i - 1], cur.first, v[i]};
      szx++;
      joinx[szx] = newi;
    }
  }
  for (auto cur : my) {
    auto v = cur.second;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
      line newi = {v[i - 1], cur.first, v[i], cur.first};
      szy++;
      joiny[szy] = newi;
    }
  }
  MatchingGraph g(szx + szy + 1);
  for (int i = 1; i <= szx; i++) {
    for (int j = 1; j <= szy; j++) {
      if (joinx[i].sy < joiny[j].sy && joiny[j].sy < joinx[i].ey &&
          joiny[j].sx < joinx[i].sx && joinx[i].sx < joiny[j].ex) {
        cant[i][j] = true;
        g.add_edge(i, j + szx);
      }
    }
  }
  int lol = g.max_matching();
  queue<int> q;
  for (int i = 1; i <= szx; i++) {
    if (g.match[i] == -1) {
      vis[i] = true;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur <= szx) {
      for (int i = 1; i <= szy; i++) {
        if (!cant[cur][i] || g.match[i + szx] == cur || vis[i + szx]) continue;
        vis[i + szx] = true;
        q.push(i + szx);
      }
    } else {
      for (int i = 1; i <= szx; i++) {
        if (!cant[i][cur - szx] || g.match[szx] != cur || vis[i]) continue;
        vis[i] = true;
        q.push(i);
      }
    }
  }
  for (int i = 1; i <= szx; i++)
    if (vis[i]) chx[i] = true;
  for (int i = 1; i <= szy; i++)
    if (!vis[i + szx]) chy[i] = true;
  int tx = 0, ty = 0;
  for (auto cur : mx) {
    auto v = cur.second;
    sort(v.begin(), v.end());
    line newi = {cur.first, v[0], cur.first, v[0]};
    for (int i = 1; i < v.size(); i++) {
      tx++;
      if (chx[tx]) {
        newi.ey = v[i];
        continue;
      }
      ansx.push_back(newi);
      newi = {cur.first, v[i], cur.first, v[i]};
    }
    ansx.push_back(newi);
  }
  for (auto cur : my) {
    auto v = cur.second;
    sort(v.begin(), v.end());
    line newi = {v[0], cur.first, v[0], cur.first};
    for (int i = 1; i < v.size(); i++) {
      ty++;
      if (chy[ty]) {
        newi.ex = v[i];
        continue;
      }
      ansy.push_back(newi);
      newi = {v[i], cur.first, v[i], cur.first};
    }
    ansy.push_back(newi);
  }
  cout << ansy.size() << endl;
  for (auto cur : ansy) {
    cout << cur.sx << ' ' << cur.sy << ' ' << cur.ex << ' ' << cur.ey << '\n';
  }
  cout << ansx.size() << endl;
  for (auto cur : ansx) {
    cout << cur.sx << ' ' << cur.sy << ' ' << cur.ex << ' ' << cur.ey << '\n';
  }
}
