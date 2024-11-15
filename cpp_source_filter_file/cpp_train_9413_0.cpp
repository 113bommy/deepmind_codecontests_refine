#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const int INF = 1000000000;
const int MOD = 1000000007;
long long dp[2][MAXN][MAXN][MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> mn[MAXN], mx[MAXN];
inline long long add(long long a, long long b) { return (a + b); }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dist[i][j] = INF;
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    dist[u][v] = dist[v][u] = c;
  }
  int g1, g2, s1, s2;
  cin >> g1 >> g2 >> s1 >> s2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  for (int i = 1; i <= n; i++) {
    mn[i] = pair<int, int>(INF, INF);
    mx[i] = pair<int, int>(0, 0);
    for (int j = 1; j <= n; j++)
      if (i != j) {
        mn[i] = min(mn[i], pair<int, int>(dist[i][j], i));
        mx[i] = max(mx[i], pair<int, int>(dist[i][j], i));
      }
  }
  for (int x = 1; x <= n; x++)
    for (int y = 1; y <= n; y++) dp[0][x][y][0][0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int x = 1; x <= n; x++)
      for (int y = 1; y <= n; y++) {
        bool canGold = false, canSilver = false, canBronze = false;
        for (int j = 1; j <= n; j++) {
          if (j == i) continue;
          canGold |= pair<int, int>(dist[i][j], i) < mx[y] &&
                     pair<int, int>(dist[i][j], i) <= mn[x];
          canSilver |= pair<int, int>(dist[i][j], i) > mn[x] &&
                       pair<int, int>(dist[i][j], i) < mx[y];
          canBronze |= pair<int, int>(dist[i][j], i) > mn[x] &&
                       pair<int, int>(dist[i][j], i) >= mx[y];
        }
        if (i == x) canSilver = canBronze = false;
        if (i == y) canGold = canSilver = false;
        for (int gs = 0; gs <= g2; gs++)
          for (int ss = 0; ss <= s2; ss++) {
            dp[i % 2][x][y][gs][ss] = 0;
            if (gs && canGold)
              dp[i % 2][x][y][gs][ss] = add(dp[i % 2][x][y][gs][ss],
                                            dp[(i + 1) % 2][x][y][gs - 1][ss]);
            if (ss && canSilver)
              dp[i % 2][x][y][gs][ss] = add(dp[i % 2][x][y][gs][ss],
                                            dp[(i + 1) % 2][x][y][gs][ss - 1]);
            if (canBronze)
              dp[i % 2][x][y][gs][ss] =
                  add(dp[i % 2][x][y][gs][ss], dp[(i + 1) % 2][x][y][gs][ss]);
            if (i == n && gs >= g1 && gs <= g2 && ss >= s1 && ss <= s2)
              ans = add(ans, dp[i % 2][x][y][gs][ss]);
          }
      }
  cout << ans << endl;
}
