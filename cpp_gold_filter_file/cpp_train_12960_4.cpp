#include <bits/stdc++.h>
int n;
struct light {
  int a, b;
} a[102];
int f[102][102][2];
int ans = -1;
int cmp(light x, light y) { return x.a < y.a; }
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x < y ? y : x; }
int main() {
  int i, j, k, jj, kk;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
  std::sort(a + 1, a + n + 1, cmp);
  a[0].a = -1000000000;
  for (i = 1; i <= n + 1; i++)
    for (j = 0; j < i; j++)
      for (k = 0; k < 2; k++) {
        int rj = a[j].a + k * a[j].b;
        int val = f[i][j][k];
        if (ans < f[i][j][k]) ans = f[i][j][k];
        int mx = 1 << 31, bj = 0, bk = 0;
        for (jj = i; jj <= n; jj++)
          for (kk = 0; kk < 2; kk++) {
            int rjj = a[jj].a + kk * a[jj].b;
            if (rjj > mx) {
              mx = rjj;
              bj = jj;
              bk = kk;
            }
            f[jj + 1][bj][bk] =
                max(f[jj + 1][bj][bk], val + min(a[jj].b, rjj - rj) + mx - rjj);
          }
      }
  printf("%d\n", ans);
  return 0;
}
