#include <bits/stdc++.h>
using namespace std;
const int maxm = 5005;
const int inf = 1000000005;
int deg[maxm];
bool vis[maxm][maxm];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    vis[a][b] = vis[b][a] = true;
    deg[a]++;
    deg[b]++;
  }
  int res = inf;
  for (int k = 0; k < n; k++) {
    for (int i = k + 1; i < n; i++) {
      if (vis[k][i]) {
        for (int j = i + 1; j < n; j++) {
          if (vis[i][j] && vis[k][j]) {
            res = min(res, deg[i] + deg[j] + deg[k]);
          }
        }
      }
    }
  }
  if (res == inf)
    cout << -1 << endl;
  else
    cout << res - 6 << endl;
  return 0;
}
