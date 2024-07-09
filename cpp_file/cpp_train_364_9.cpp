#include <bits/stdc++.h>
using namespace std;
int f[11][11];
int main() {
  int n;
  scanf("%d", &n);
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &f[i][j]);
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  int ans = -1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ans = max(ans, f[i][j]);
  cout << ans << endl;
  return 0;
}
