#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const long long infll = (long long)1.01e18;
const long double eps = 1e-9;
const long double pi = acos((long double)-1);
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }
void precalc() {}
const int mod = (int)1e9 + 7;
int mul(int a, int b) { return (long long)a * b % mod; }
void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
const int maxn = 105, maxk = 22;
int n, k;
vector<int> g[maxn];
bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}
int dp[maxn][maxk][maxk];
int ndp[maxk][maxk];
void dfs(int v, int p) {
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      dp[v][i][j] = 0;
    }
  }
  if (k) {
    dp[v][k][1] = 1;
  }
  dp[v][0][0] = 1;
  for (int it = 0; it < ((int)(g[v]).size()); it++) {
    int u = g[v][it];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    memset(ndp, 0, sizeof(ndp));
    for (int iv = 0; iv <= k; iv++) {
      for (int jv = 0; jv <= k; jv++) {
        auto &curv = dp[v][iv][jv];
        if (!curv) {
          continue;
        }
        for (int iu = 0; iu <= k; iu++) {
          for (int ju = 0; ju <= k; ju++) {
            auto &curu = dp[u][iu][ju];
            if (!curu) {
              continue;
            }
            int ni = min(iv, iu + 1);
            int nj = max((iv + ju <= k ? 0 : ju + 1), (jv + iu <= k ? 0 : iu));
            if (nj > k) {
              continue;
            }
            add(ndp[ni][nj], mul(curv, curu));
          }
        }
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        dp[v][i][j] = ndp[i][j];
      }
    }
  }
}
void solve() {
  dfs(0, -1);
  int res = 0;
  for (int i = 0; i <= k; i++) {
    add(res, dp[0][i][0]);
  }
  printf("%d\n", res);
}
int main() {
  precalc();
  while (read()) {
    solve();
  }
  return 0;
}
