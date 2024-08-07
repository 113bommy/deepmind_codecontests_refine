#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool v[1005][1005];
int N, M;
int ans;
vector<pair<int, int> > vis;
bool ok;
int dir[8][2] = {{0, 1},  {1, 0}, {0, -1}, {-1, 0},
                 {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
void flood(int r, int c) {
  a[r][c] = '2';
  for (int i = 0; i < 8; ++i) {
    int r1 = r + dir[i][0], c1 = c + dir[i][1];
    if (a[r1][c1] == 0) ok = 0;
    if (a[r1][c1] == '1' && !v[r1][c1]) {
      v[r1][c1] = 1;
      vis.push_back(make_pair(r1, c1));
    }
    if (a[r1][c1] == '0') flood(r1, c1);
  }
}
int dfs(int r, int c) {
  v[r][c] = 0;
  int ret = 1;
  for (int i = 0; i < 4; ++i) {
    int r1 = r + dir[i][0], c1 = c + dir[i][1];
    if (v[r1][c1]) ret += dfs(r1, c1);
  }
  return ret;
}
void check() {
  int r, c;
  int sz = vis.size();
  for (int i = 0; i < sz; ++i) {
    int cnt = 0;
    r = vis[i].first, c = vis[i].second;
    for (int j = 0; j < 4; ++j) {
      int r1 = r + dir[j][0], c1 = c + dir[j][1];
      if (v[r1][c1]) cnt++;
    }
    if (cnt != 2) ok = 0;
  }
  if (ok) {
    int t = dfs(r, c);
    if (t == vis.size()) ans = max(ans, (int)vis.size());
  }
  for (int i = 0; i < sz; ++i) v[vis[i].first][vis[i].second] = 0;
  vis.clear();
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; ++i) scanf("%s", a[i] + 1);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      ok = 1;
      if (a[i][j] == '0') {
        flood(i, j);
        check();
      } else if (a[i][j] == '1' && a[i - 1][j] == '1' && a[i][j - 1] == '1' &&
                 a[i - 1][j - 1] == '1')
        ans = max(ans, 4);
    }
  printf("%d\n", ans);
  return 0;
}
