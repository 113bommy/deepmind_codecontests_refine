#include <bits/stdc++.h>
int a[3][3003], b[3003][2], n, i, j, k;
int main() {
  scanf("%d", &n);
  for (; k < 3; ++k)
    for (i = 1; i <= n; ++i) scanf("%d", &a[k][i]);
  b[0][0] = -1e6;
  for (i = 1; i <= n; ++i)
    for (k = 0; k < 2; ++k)
      for (j = 0; j < 2; ++j)
        if (b[i][k] < b[i - 1][j] + a[1 + k - j][i])
          b[i][k] = b[i - 1][j] + a[1 + k - j][i];
  printf("%d\n", b[n][0]);
}
