#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, p, x, t, y, num, a[34], b[34], u, flag, q[34];
bool f[34][34][50010], tot[34][34][50010];
int add(int x, int y) {
  if (y >= 10)
    x *= 100;
  else
    x *= 10;
  x = (x + y) % p;
  return x;
}
int main() {
  scanf("%d%d", &n, &p);
  f[0][0][0] = 1;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (x < 32) {
      t++;
      a[t] = x;
      b[t] = i;
      for (j = 0; j < 32; ++j)
        for (k = 0; k < p; ++k)
          if (f[t - 1][j][k]) {
            f[t][j][k] = 1;
            tot[t][j][k] = 0;
            y = add(k, x);
            f[t][j ^ x][y] = 1;
            tot[t][j ^ x][y] = 1;
            if (j == x && y == 0) {
              flag = 1;
              goto aaa;
            }
          }
    }
  }
aaa:;
  if (flag) {
    printf("Yes\n");
    for (u = 0, y = 0, i = t; i >= 1; --i) {
      if (tot[i][u][y]) {
        q[++num] = b[i];
        u ^= a[i];
        for (j = 0; j < p; ++j)
          if (f[i - 1][u][j] && add(j, a[i]) == y) {
            y = j;
            break;
          }
      }
    }
    printf("%d\n", num);
    for (i = num; i >= 1; --i) printf("%d ", q[i]);
  } else
    printf("No\n");
}
