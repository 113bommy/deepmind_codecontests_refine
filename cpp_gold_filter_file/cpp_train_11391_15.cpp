#include <bits/stdc++.h>
using namespace std;
int x, y, z, cnt[120000][3], l, r, i, n, j, m;
char c[120000];
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (i = 1; i <= n; ++i) {
    for (j = 0; j < 3; ++j) cnt[i][j] = cnt[i - 1][j];
    cnt[i][c[i] - 'x']++;
  }
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    if (r - l + 1 < 3) {
      printf("YES\n");
      continue;
    }
    x = cnt[r][0] - cnt[l - 1][0];
    y = cnt[r][1] - cnt[l - 1][1];
    z = cnt[r][2] - cnt[l - 1][2];
    if (abs(x - y) <= 1 && abs(y - z) <= 1 && abs(x - z) <= 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
