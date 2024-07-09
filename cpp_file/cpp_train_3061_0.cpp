#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 110;
const int M = N * N;
int n, m;
vector<int> lst[M];
int op[M], ed[M];
int G[N][N];
int g[2][2][N][N][N], f[N][N][2];
int a[N][N][N], b[N][N][N];
inline pair<int, int> calc(vector<int> &tp, int x, bool flg) {
  for (int i = 0; i < tp.size(); i++) {
    int y = tp[i], t = G[x][y];
    if (!t || tp.size() > 2 * n || (t > m) != flg)
      return pair<int, int>(0xdeaded, -1);
    for (auto j : lst[t]) tp.push_back(j);
    x = y;
  }
  return pair<int, int>(tp.size(), x);
}
inline void solve(bool flg) {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int lb = !flg ? 1 : m + 1, rb = !flg ? m : 2 * m;
  for (int i = lb; i <= rb; i++)
    for (auto p = lst[i].begin(); p != lst[i].end(); p++)
      if (*p == op[i]) {
        vector<int> t1(lst[i].begin(), p);
        reverse(t1.begin(), t1.end());
        pair<int, int> rs = calc(t1, op[i], !flg);
        if (rs.first > 2 * n) continue;
        if (p + 1 == lst[i].end())
          b[rs.second][ed[i]][rs.first + 1]++;
        else {
          if (*(p + 1) != ed[i]) continue;
          vector<int> t2(p + 2, lst[i].end());
          pair<int, int> rs2 = calc(t2, ed[i], flg);
          if (rs.first + rs2.first + 1 <= 2 * n)
            a[rs.second][rs2.second][rs.first + rs2.first + 1]++;
        }
      }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &op[i], &ed[i]);
    G[op[i]][ed[i]] = i;
    op[i + m] = ed[i];
    ed[i + m] = op[i];
    G[op[i + m]][ed[i + m]] = i + m;
    int k;
    scanf("%d", &k);
    for (int j = 1, u; j <= k; j++) scanf("%d", &u), lst[i].push_back(u);
    lst[i + m] = lst[i];
    reverse(lst[i + m].begin(), lst[i + m].end());
    if (!k) g[0][0][op[i]][ed[i]][1]++;
  }
  solve(0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= 2 * n; k++)
        g[1][0][i][j][k] = b[i][j][k], g[1][1][i][j][k] = a[i][j][k];
  solve(1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= 2 * n; k++) g[0][1][j][i][k] = b[i][j][k];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= 2 * n; k++)
        for (int l = 0; l < 2; l++) (f[k][j][l] += g[1][l][i][j][k]) %= MOD;
  for (int k = 1; k <= 2 * n; k++) {
    int rs = 0;
    for (int i = 1; i <= n; i++) {
      (rs += f[k][i][1]) %= MOD;
      for (int l = 0; l < 2; l++)
        if (f[k][i][l])
          for (int p = 0; p < 2; p++)
            for (int j = 1; j <= n; j++)
              for (int len = 1; len <= 2 * n - k; len++)
                (f[k + len][j][p] +=
                 1ll * f[k][i][l] * g[l ^ 1][p][i][j][len] % MOD) %= MOD;
    }
    printf("%d\n", rs);
  }
  return 0;
}
