#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& cerr, vector<long long> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}
struct state {
  int x, y;
  int where;
};
const int maxN = 100011;
const int maxD = 52;
const int init = 1000000000;
int n, m, d, x, y;
vector<int> adj[maxN], rev[maxN];
char open[maxN][maxD];
bool us[maxN][maxD];
int best[maxN][maxD];
stack<pair<int, int> > S;
int nxt[maxD], previous[maxD];
vector<pair<int, int> > here;
int best_here;
int cnt_vis;
bool vis[maxN];
int sol;
stack<state> dfStack;
void dfs(int x, int y) {
  int wh;
  dfStack.push({x, y, 0});
  while (!dfStack.empty()) {
    auto act = dfStack.top();
    dfStack.pop();
    x = act.x;
    y = act.y;
    wh = act.where;
    us[x][y] = true;
    while (wh < adj[x].size() && us[adj[x][wh]][nxt[y]]) wh++;
    if (wh == adj[x].size()) {
      S.push(make_pair(x, y));
      continue;
    } else {
      dfStack.push({x, y, wh + 1});
      dfStack.push({adj[x][wh], nxt[y], 0});
    }
  }
}
void dfs2(int x, int y) {
  int wh;
  dfStack.push({x, y, 0});
  while (!dfStack.empty()) {
    auto act = dfStack.top();
    dfStack.pop();
    x = act.x;
    y = act.y;
    wh = act.where;
    us[x][y] = true;
    if (wh == 0) {
      here.push_back(make_pair(x, y));
      best_here = max(best_here, best[x][y]);
      if (open[x][y] == '1' && vis[x] == false) {
        vis[x] = true;
        cnt_vis++;
      }
    }
    while (wh < rev[x].size() && us[rev[x][wh]][previous[y]]) wh++;
    if (wh == rev[x].size()) {
      continue;
    } else {
      dfStack.push({x, y, wh + 1});
      dfStack.push({rev[x][wh], previous[y], 0});
    }
  }
}
int main() {
  scanf("%d%d%d\n", &n, &m, &d);
  int a = 5 / 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d\n", &x, &y);
    adj[x].push_back(y);
    rev[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) scanf("%s\n", open[i]);
  for (int i = 0; i < d; i++) {
    nxt[i] = (i + 1) % d;
    previous[i] = (i - 1 + d) % d;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < d; j++) {
      if (us[i][j]) continue;
      dfs(i, j);
    }
  }
  memset(us, 0, sizeof(us));
  best[1][0] = init;
  while (!S.empty()) {
    auto act = S.top();
    S.pop();
    x = act.first;
    y = act.second;
    if (us[x][y]) continue;
    here.clear();
    best_here = 0;
    cnt_vis = 0;
    dfs2(x, y);
    for (auto e : here) {
      x = e.first;
      y = e.second;
      best[x][y] = best_here + cnt_vis;
      for (auto to : adj[x]) {
        best[to][nxt[y]] = max(best[to][nxt[y]], best[x][y]);
      }
      vis[x] = false;
    }
    sol = max(sol, best_here + cnt_vis);
    continue;
    cerr << best_here + cnt_vis << '\n';
    for (auto e : here) cerr << e.first << " " << e.second << '\n';
  }
  printf("%d", sol - init);
  return 0;
}
