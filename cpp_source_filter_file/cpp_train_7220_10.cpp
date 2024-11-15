#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[3030];
vector<int> t[3030];
int n, d[3030], y = 9999;
bool u[3030];
void read(void) {
  cin >> n;
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    g[a].push_back(make_pair(b, 0));
    g[b].push_back(make_pair(a, 1));
  }
}
int run(int v, int de) {
  u[v] = 1;
  d[v] = de;
  int ans = 0;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    int to = g[v][i].first;
    int bo = g[v][i].second;
    if (!u[to]) {
      ans += bo;
      if (bo == 1)
        ans += run(to, de - 1);
      else
        ans += run(to, de + 1);
      t[v].push_back(to);
    }
  }
  return ans;
}
int dfs(int v) {
  int ans = d[v];
  for (int i = 0; i < (int)t[i].size(); ++i) {
    int to = t[v][i];
    ans = min(ans, dfs(to));
  }
  return ans;
}
void kill(int v) {
  for (int i = 1; i <= n; ++i) u[i] = 0, t[i].clear();
  int ans = run(v, 0);
  int m1 = 100000, m2 = 100000;
  for (int i = 0; i < (int)t[v].size(); ++i) {
    int to = t[v][i];
    int x = dfs(to);
    if (m1 < x)
      m2 = min(m2, x);
    else
      m2 = m1, m1 = x;
  }
  y = min(y, ans + m1 + m2);
  y = min(y, ans);
}
int main() {
  read();
  for (int i = 1; i <= n; ++i) kill(i);
  cout << y << "\n";
  return 0;
}
