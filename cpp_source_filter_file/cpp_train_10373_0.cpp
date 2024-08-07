#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005, MOD = 1000000007;
int f[MAXN][MAXN], g[MAXN];
long long a[MAXN];
char b[55][MAXN];
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  f[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j - 1] + (long long)f[i - 1][j] * j) % MOD;
    for (int j = 1; j <= i; j++) g[i] = (g[i] + f[i][j]) % MOD;
  }
  for (int i = 0; i < n; i++) scanf("%s", b[i]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (b[j][i] == '1') a[i] |= 1 << j;
  sort(a, a + m);
  int ans = 1;
  for (int i = 0; i < m;) {
    int j;
    for (j = i + 1; j < m && a[j] == a[i]; j++)
      ;
    ans = (long long)ans * g[j - i] % MOD;
    i = j;
  }
  printf("%d", ans);
  return 0;
}
