#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[100];
int n, m, x, y;
char s[10];
long long dp[100][100];
int check2(int l, int r, int x, int y) {
  for (int i = 0; i < g[x].size(); ++i) {
    int z = g[x][i].first, w = g[x][i].second;
    if (w == 1) {
      if (z < l || z > r) return 0;
    }
    if (w == 2) {
      if (l <= z && z <= r && z != x && z != y) return 0;
    }
    if (w == 3) {
      if (z < l || z > r || z == x || z == y) return 0;
    }
    if (w == 4) {
      if (z != x && z != y) return 0;
    }
    if (w == 5) {
      if (l <= z && z <= r) return 0;
    }
  }
  return 1;
}
int check(int l, int r, int x, int y) {
  if (!check2(l, r, x, y)) return 0;
  if (!check2(l, r, y, x)) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%s%d", &x, s, &y);
    if (strlen(s) == 2) {
      if (s[0] == '<')
        g[x].push_back(make_pair(y, 1));
      else if (s[0] == '>')
        g[x].push_back(make_pair(y, 2));
    } else {
      if (s[0] == '<')
        g[x].push_back(make_pair(y, 3));
      else if (s[0] == '=')
        g[x].push_back(make_pair(y, 4));
      else if (s[0] == '>')
        g[x].push_back(make_pair(y, 5));
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < 2 * n; ++i) dp[i][i + 1] = check(i, i + 1, i, i + 1);
  for (int i = 4; i <= 2 * n; i += 2)
    for (int l = 1; l + i - 1 <= 2 * n; ++l) {
      int r = l + i - 1;
      if (check(l, r, l, r)) dp[l][r] += dp[l + 1][r - 1];
      if (check(l, r, l, l + 1)) dp[l][r] += dp[l + 2][r];
      if (check(l, r, r - 1, r)) dp[l][r] += dp[l][r - 2];
    }
  printf("%d\n", dp[1][2 * n]);
  return 0;
}
