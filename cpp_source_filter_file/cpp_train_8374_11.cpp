#include <bits/stdc++.h>
using namespace std;
int FALSEFLAG;
int color[100005];
int flag[100005];
vector<pair<int, int> > edge[100005];
int cnt[100005];
int tot = 0;
int n, k;
void dfs(int i) {
  if (FALSEFLAG) return;
  flag[i] = 1;
  for (int j = 0; j < edge[i].size(); j++) {
    int t = edge[i][j].first;
    int p = edge[i][j].second;
    if (!flag[t]) {
      color[i] = color[t] ^ p;
      dfs(t);
    } else if (color[i] ^ color[t] != p) {
      FALSEFLAG = 1;
    }
  }
}
void add(int x, int y, int p) {
  edge[x].push_back(make_pair(y, p));
  edge[y].push_back(make_pair(x, p));
}
void addedge(int x, int y, int p) {
  if (x > y) return addedge(y, x, p);
  int ty = y + x - 1;
  if (ty > n) ty = n - (ty ^ n & 1);
  add(y - x, ty + 1, p);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    char o;
    int eq;
    cin >> x >> y >> o;
    if (o == 'o')
      eq = 1;
    else
      eq = 0;
    addedge(x, y, eq);
  }
  dfs(0);
  dfs(1);
  long long ans = 1;
  for (int i = 2; i <= n + 1; i++)
    if (!flag[i]) {
      dfs(i);
      (ans *= 2) %= 1000000007;
    }
  if (FALSEFLAG)
    cout << 0 << endl;
  else
    cout << ans << endl;
}
