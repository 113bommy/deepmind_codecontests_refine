#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int q, dp[31][8], sum[30][8], k;
void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}
void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += M;
}
int find(int x, int y) {
  if (x < 0 || y < 0) return 0;
  int ret = 0;
  memset(dp, 0, sizeof dp);
  memset(sum, 0, sizeof sum);
  dp[30][0] = 1;
  for (int i = 30; i; i--)
    for (int j = 0; j < 8; j++)
      if (dp[i][j])
        for (int at = 0; at < 4; at++) {
          bool bitx = at & 1, bity = at & 2;
          if (bitx && !(x & (1 << i)) && !(j & 4)) continue;
          if (bity && !(y & (1 << i)) && !(j & 2)) continue;
          if ((bitx ^ bity) && !(k & (1 << i)) && !(j & 1)) continue;
          int to = j;
          to |= 4 * (bitx < !!(x & (1 << i)));
          to |= 2 * (bity < !!(y & (1 << i)));
          to |= (bitx ^ bity) < !!(k & (1 << i));
          add(dp[i - 1][to], dp[i][j]);
          add(sum[i - 1][to], sum[i][j]);
          add(sum[i - 1][to], ((bitx ^ bity) << i) * 1LL * dp[i][j] % M);
          bitset<3> a(j), b(to);
        }
  int i = 0;
  for (int j = 0; j < 8; j++)
    for (int at = 0; at < 4; at++) {
      bool bitx = at & 1, bity = at & 2;
      if (bitx && !(x & (1 << i)) && !(j & 4)) continue;
      if (bity && !(y & (1 << i)) && !(j & 2)) continue;
      if ((bitx ^ bity) && !(k & (1 << i)) && !(j & 1)) continue;
      add(ret, (bitx ^ bity) * dp[i][j]);
      add(ret, dp[i][j]);
      add(ret, sum[i][j]);
    }
  return ret;
}
int main() {
  scanf("%d", &q);
  while (q--) {
    int x, x1, y, y1;
    scanf("%d%d%d%d%d", &x, &y, &x1, &y1, &k);
    x--;
    y--;
    x1--;
    y1--;
    k--;
    int ans = 0;
    add(ans, find(x1, y1));
    sub(ans, find(x - 1, y1));
    sub(ans, find(x1, y - 1));
    add(ans, find(x - 1, y - 1));
    printf("%d\n", ans);
  }
}
