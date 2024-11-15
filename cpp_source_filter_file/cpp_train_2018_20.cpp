#include <bits/stdc++.h>
using namespace std;
double C[52][52], p[52][52][52], Ans = 0;
int a[52], n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", a + i);
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  p[0][0][0] = 1;
  for (int j = 1; j <= m; j++)
    for (int i = 0; i < n; i++)
      for (int k = 0; k <= n; k++)
        for (int l = 0; l <= n - i; l++)
          p[i + l][j][max(k, l / a[j] + (l % a[j] != 0))] +=
              p[i][j - 1][k] * C[n - i][l] * pow((double)1 / (m - j + 1), l) *
              pow((double)(m - j) / (m - j + 1), n - i - l);
  for (int i = 0; i <= n; i++) Ans += p[n][m][i] * i;
  printf("%.9lf", Ans);
  return 0;
}
