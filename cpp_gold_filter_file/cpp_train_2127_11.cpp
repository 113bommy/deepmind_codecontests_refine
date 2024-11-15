#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50;
int cost[3][3];
long long f[MAX_N][3][3];
int n;
int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) scanf("%d", &cost[i][j]);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        int x = 3 - j - k;
        f[i][j][k] = f[i - 1][j][x] + cost[j][k] + f[i - 1][x][k];
        f[i][j][k] =
            min(f[i][j][k], f[i - 1][j][k] + cost[j][x] + f[i - 1][k][j] +
                                cost[x][k] + f[i - 1][j][k]);
      }
    }
  }
  printf("%I64d\n", f[n][0][2]);
  return 0;
}
