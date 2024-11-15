#include <bits/stdc++.h>
using namespace std;
const int Sn = 2550;
int n, m, K, a[Sn][Sn];
int s[Sn][Sn];
int ht[2][8];
long long Ans;
int sum(int x1, int x2, int y1, int y2) {
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
void solve(int x1, int x2, int y1, int y2) {
  if (x1 == x2) {
    for (int l = y1; l <= y2; l++)
      for (int r = l; r <= y2; r++) Ans += (sum(x1, x2, l, r) == K);
  } else if (y1 == y2) {
    for (int l = x1; l <= x2; l++)
      for (int r = l; r <= x2; r++) Ans += (sum(l, r, y1, y2) == K);
  }
  if (x1 >= x2 || y1 >= y2) return;
  if (x2 - x1 > y2 - y1) {
    int x0 = (x1 + x2) / 2, l, r, *t;
    for (l = y1; l <= y2; l++) {
      for (int i = 0; i <= K; i++) ht[0][i] = x0 - x1 + 1, ht[1][i] = x2 - x0;
      for (r = l; r <= y2; r++) {
        for (int k = 0; k <= K; k++) {
          t = &ht[0][k];
          while ((*t) && sum(x0 - (*t) + 1, x0, l, r) > k) (*t)--;
          t = &ht[1][k];
          while ((*t) && sum(x0 + 1, x0 + (*t), l, r) > k) (*t)--;
        }
        for (int k = 0; k <= K; k++) {
          int lf = ht[0][k] - (k - 1 >= 0 ? ht[0][k - 1] : 0);
          k = K - k;
          int rf = ht[1][k] - (k - 1 >= 0 ? ht[1][k - 1] : 0);
          k = K - k;
          Ans += (long long)lf * rf;
        }
      }
    }
    solve(x1, x0, y1, y2);
    solve(x0 + 1, x2, y1, y2);
  } else {
    int y0 = (y1 + y2) / 2, l, r, *t;
    for (l = x1; l <= x2; l++) {
      for (int i = 0; i <= K; i++) ht[0][i] = y0 - y1 + 1, ht[1][i] = y2 - y0;
      for (r = l; r <= x2; r++) {
        for (int k = 0; k <= K; k++) {
          t = &ht[0][k];
          while ((*t) && sum(l, r, y0 - (*t) + 1, y0) > k) (*t)--;
          t = &ht[1][k];
          while ((*t) && sum(l, r, y0 + 1, y0 + (*t)) > k) (*t)--;
        }
        for (int k = 0; k <= K; k++) {
          int lf = ht[0][k] - (k - 1 >= 0 ? ht[0][k - 1] : 0);
          k = K - k;
          int rf = ht[1][k] - (k - 1 >= 0 ? ht[1][k - 1] : 0);
          k = K - k;
          Ans += (long long)lf * rf;
        }
      }
    }
    solve(x1, x2, y1, y0);
    solve(x1, x2, y0 + 1, y2);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char cmd;
      do {
        cmd = getchar();
      } while (cmd != '0' && cmd != '1');
      a[i][j] = cmd - '0';
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  solve(1, n, 1, m);
  printf("%I64d\n", Ans);
}
