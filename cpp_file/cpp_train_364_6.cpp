#include <bits/stdc++.h>
using namespace std;
int f[11][11], n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> f[i][j];
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
      }
  int p = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      p = max(p, f[i][j]);
    }
  cout << p << endl;
  return 0;
}
