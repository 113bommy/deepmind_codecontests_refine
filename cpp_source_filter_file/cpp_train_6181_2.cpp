#include <bits/stdc++.h>
using namespace std;
int n;
bitset<100005> f[65], t[65];
int w[100005], ans[100005];
int main() {
  scanf("%d", &n);
  int i, j;
  long long a, x = 0;
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a);
    x ^= a;
    for (j = 0; j <= 60; j++)
      if ((a >> j & 1) == 1) f[j][i] = 1;
  }
  for (j = 0; j <= 60; j++) f[j][n] = ~x >> j & 1;
  int p = -1, l;
  for (int k = 0; k <= 1; k++)
    for (i = 60; i >= 0; i--) {
      if ((x >> i & 1) == k) {
        t[++p] = f[i];
        w[p] = 1000000;
        for (j = 0; j < p; j++)
          if (t[p][w[j]] == 1) t[p] ^= t[j];
        for (j = 0; j <= n; j++)
          if (t[p][j] == 1) {
            l = j;
            break;
          }
        if (l >= n)
          p--;
        else {
          w[p] = l;
          for (j = 0; j < p; j++)
            if (t[j][w[p]] == 1) t[j] ^= t[p];
        }
      }
    }
  for (i = 0; i <= p; i++) ans[w[i]] = t[i][n];
  for (i = 0; i < n; i++) printf("%d ", 2 - ans[i]);
  printf("\n");
  return 0;
}
