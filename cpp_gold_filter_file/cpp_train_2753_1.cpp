#include <bits/stdc++.h>
int a[15][200000][15];
int b[15] = {0};
int main() {
  a[1][0][0] = 0;
  b[1] = 1;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < b[i]; j++) {
      int m = 0;
      for (int k = 0; k <= i; k++)
        if (a[i][j][k] > m) m = a[i][j][k];
      m++;
      if (j % 2 == 0) {
        for (int k = 0; k <= i; k++) a[i + 1][b[i + 1]][k] = a[i][j][k];
        a[i + 1][b[i + 1]][i + 1] = 0;
        b[i + 1]++;
        for (int r = m; r > 0; r--) {
          for (int k = 0; k <= i; k++) a[i + 1][b[i + 1]][k] = a[i][j][k];
          a[i + 1][b[i + 1]][i + 1] = r;
          b[i + 1]++;
        }
      } else {
        for (int r = 1; r <= m; r++) {
          for (int k = 0; k <= i; k++) a[i + 1][b[i + 1]][k] = a[i][j][k];
          a[i + 1][b[i + 1]][i + 1] = r;
          b[i + 1]++;
        }
        for (int k = 0; k <= i; k++) a[i + 1][b[i + 1]][k] = a[i][j][k];
        a[i + 1][b[i + 1]][i + 1] = 0;
        b[i + 1]++;
      }
    }
  }
  printf("%d\n", b[n]);
  for (int i = 0; i < b[n]; i++) {
    int m = 0;
    for (int j = 1; j <= n; j++)
      if (a[n][i][j] > m) m = a[n][i][j];
    for (int j = 0; j <= m; j++) {
      if (j > 0) printf(",");
      printf("{");
      bool first = true;
      for (int k = 1; k <= n; k++)
        if (a[n][i][k] == j) {
          if (first)
            first = false;
          else
            printf(",");
          printf("%d", k);
        }
      printf("}");
    }
    printf("\n");
  }
}
