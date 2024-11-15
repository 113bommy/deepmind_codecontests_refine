#include <bits/stdc++.h>
using namespace std;
const int MAXN = 512;
char g[MAXN][MAXN];
int a[MAXN][MAXN];
int s[MAXN][MAXN], x[MAXN];
int n, m, k;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> g[i];
  for (int i = 1; i + 1 < n; ++i) {
    for (int j = 1; j + 1 < m; ++j)
      if (g[i][j] == '1' && g[i][j - 1] == '1' && g[i][j + 1] == '1' &&
          g[i + 1][j] == '1' && g[i - 1][j] == '1')
        a[i][j] = 1;
    partial_sum(a[i], a[i] + m, s[i]);
  }
  long long ans = 0;
  for (int i = 1; i + 1 < m; ++i)
    for (int j = i; j + 1 < m; ++j) {
      for (int p = 1; p + 1 < n; ++p) x[p] = x[p - 1] + s[p][j] - s[p][i - 1];
      for (int p = 1, q = 1; p + 1 < n; ++p) {
        while (q + 1 < n && x[q] - x[p - 1] < k) {
          ++q;
        }
        ans += n - q - 1;
      }
    }
  cout << ans << endl;
  return 0;
}
