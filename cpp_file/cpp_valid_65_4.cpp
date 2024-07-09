#include <bits/stdc++.h>
const int N = 1e5 + 7, M = 50 + 7, mod = 998244353;
int prime[N], mu[N], l[M], r[M], r_[M], sum_[N], sum[N], dp[M][N];
bool p[N];
inline void init(int n) {
  int cnt = 0;
  p[0] = p[1] = true;
  mu[1] = 1;
  for (register int i = 2; i <= n; i++) {
    if (!p[i]) {
      prime[++cnt] = i;
      mu[i] = -1;
    }
    for (register int j = 1; j <= cnt && i * prime[j] <= n; j++) {
      int t = i * prime[j];
      p[t] = true;
      if (i % prime[j] == 0) {
        mu[t] = 0;
        break;
      }
      mu[t] = -mu[i];
    }
  }
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int do_dp(int n, int m) {
  int ans = 0;
  for (register int i = 0; i <= m; i++) {
    sum_[i] = 1;
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = 0; j <= m; j++) {
      int t = min(r_[i], j);
      if (i == n) ans = (ans + sum_[t]) % mod;
      sum[j] = sum_[t];
      if (j > 0) sum[j] = (sum[j] + sum[j - 1]) % mod;
    }
    for (register int j = 0; j <= m; j++) {
      sum_[j] = sum[j];
    }
  }
  return ans;
}
int main() {
  int n, m, mi, ans = 0;
  scanf("%d %d", &n, &m);
  mi = m + 1;
  init(m);
  for (register int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
  }
  for (register int i = 1; i <= m; i++) {
    int sum = 0, tm = m / i;
    for (register int k = 1; k <= n; k++) {
      int tl = (l[k] - 1) / i + 1;
      r_[k] = r[k] / i - tl;
      sum = min(sum + tl, mi);
    }
    if (tm >= sum) ans = ((ans + mu[i] * do_dp(n, tm - sum)) % mod + mod) % mod;
  }
  printf("%d", ans);
  return 0;
}
