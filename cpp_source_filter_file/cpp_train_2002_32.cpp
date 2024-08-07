#include <bits/stdc++.h>
using namespace std;
const int maxn = 600;
int dp[maxn][maxn], arr[maxn];
string a[maxn];
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 1; i < m - 1; i++)
    for (int j = 1; j < n - 1; j++) {
      dp[i][j] = dp[i][j - 1];
      if (a[i][j] == '1' && a[i - 1][j] == '1' && a[i][j - 1] == '1' &&
          a[i + 1][j] == '1' && a[i][j + 1] == '1')
        dp[i][j]++;
    }
  int ans = 0;
  for (int a = 0; a < n; a++)
    for (int b = a + 2; b < n; b++) {
      for (int p = 0; p < m; p++) arr[p] = dp[p][b - 1] - dp[p][a];
      int j = 2, t = arr[1];
      for (int i = 0; i < m - 2 && j < m; i++) {
        while ((i > j - 2 || t < k) && j < m) {
          t += arr[j];
          j++;
        }
        ans += m - j;
        t -= arr[i + 1];
      }
    }
  cout << ans << endl;
}
