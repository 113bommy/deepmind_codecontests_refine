#include <bits/stdc++.h>
using namespace std;
int n, m, K, v;
int a[111][111];
int ans = 0;
int main() {
  cin >> n >> m >> v >> K;
  int x, y;
  for (int i = 0; i < v; i++) {
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= n; k++)
        for (int l = 1; l <= m; l++)
          if (i <= l && j <= l) {
            int c = 0;
            for (int aa = i; aa <= k; aa++)
              for (int b = j; b <= l; b++) c += a[aa][b];
            ans += (c >= K);
          }
    }
  cout << ans << endl;
  return 0;
}
