#include <bits/stdc++.h>
using namespace std;
int n, ans;
int f[17][17];
int main() {
  cin >> n;
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= n; j++) cin >> f[i][j];
  for (register int k = 1; k <= n; k++)
    for (register int i = 1; i <= n; i++)
      for (register int j = 1; j <= n; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= n; j++) ans = max(ans, f[i][j]);
  cout << ans;
  return 0;
}
