#include <bits/stdc++.h>
int n;
int f[11][200001][11];
int sum[11];
void check(int i, int j, int q) {
  int stk[11];
  stk[0] = 0;
  for (int k = 1; k < i; k++)
    if (f[i - 1][j][k] == k) stk[++stk[0]] = k;
  stk[++stk[0]] = i;
  if (q)
    for (int k = 1; k <= stk[0]; k++) {
      sum[i]++;
      for (int l = 1; l < i; l++) f[i][sum[i]][l] = f[i - 1][j][l];
      f[i][sum[i]][i] = stk[k];
    }
  else
    for (int k = stk[0]; k >= 1; k--) {
      sum[i]++;
      for (int l = 1; l < i; l++) f[i][sum[i]][l] = f[i - 1][j][l];
      f[i][sum[i]][i] = stk[k];
    }
}
int main() {
  scanf("%d", &n);
  f[1][1][1] = 1;
  sum[1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= sum[i - 1]; j++) check(i, j, i + j & 1);
  printf("%d\n", sum[n]);
  for (int i = 1; i <= sum[n]; i++) {
    bool ok = 0;
    for (int j = 1; j <= n; j++) {
      if (f[n][i][j] != j) continue;
      if (ok) printf(",");
      ok = 1;
      printf("{%d", j);
      for (int k = j + 1; k <= n; k++)
        if (f[n][i][j] == f[n][i][k]) printf(",%d", k);
      printf("}");
    }
    printf("\n");
  }
  return 0;
}
