#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
const int maxr = 5000 + 5;
long double dp1[maxn][maxr];
long double dp[maxn][maxr];
int n, r;
int s[maxn], f[maxn];
int postsum[maxn];
int top = 0;
long double p[maxn];
const long double eps = 1e-9;
bool check(long double q) {
  for (int i = 0; i <= r; i++) {
    dp[n][i] = 0;
  }
  for (int i = r + 1; i <= top; i++) {
    dp[n][i] = q;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= top; j++) {
      dp[i][j] = p[i] * min(q + f[i], dp[i + 1][j + f[i]] + f[i]) +
                 (1 - p[i]) * min(q + s[i], dp[i + 1][j + s[i]] + s[i]);
    }
  }
  if (dp[0][0] >= q) {
    return true;
  } else {
    return false;
  }
}
int main() {
  while (~scanf("%d%d", &n, &r)) {
    top = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%Lf", f + i, s + i, p + i);
      top += s[i];
      p[i] /= 100.0L;
    }
    long double L = 0, R = 1e9 + 7;
    while (L + eps < R) {
      const long double mid = L + (R - L) / 2;
      if (check(mid)) {
        L = mid;
      } else {
        R = mid;
      }
    }
    printf("%.10Lf\n", L);
  }
}
