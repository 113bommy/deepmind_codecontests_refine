#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
bool f[maxn][maxn][maxn];
int check(int i, int j, int k) {
  if (!f[i][j][k]) return 0;
  if (f[i - 1][j][k] && f[i + 1][j][k]) return 1;
  if (f[i][j - 1][k] && f[i][j + 1][k]) return 1;
  if (f[i][j][k - 1] && f[i][j][k + 1]) return 1;
  if (f[i - 1][j][k]) {
    if (f[i][j + 1][k] && !f[i - 1][j + 1][k]) return 1;
    if (f[i][j][k + 1] && !f[i - 1][j][k + 1]) return 1;
  }
  if (f[i][j - 1][k]) {
    if (f[i + 1][j][k] && !f[i + 1][j - 1][k]) return 1;
    if (f[i][j][k + 1] && !f[i][j - 1][k + 1]) return 1;
  }
  if (f[i][j][k - 1]) {
    if (f[i + 1][j][j] && !f[i + 1][j][k - 1]) return 1;
    if (f[i][j + 1][k] && !f[i][j + 1][k - 1]) return 1;
  }
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    for (int j = 1; j <= m; j++) {
      cin >> s;
      for (int l = 1; l <= k; l++) {
        f[i][j][l] = (s[l - 1] == '1');
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int l = 1; l <= k; l++) {
        ans += check(i, j, l);
      }
    }
  }
  cout << ans;
  return 0;
}
