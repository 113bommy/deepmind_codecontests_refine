#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001], nex[100001], c[100001], g[100001];
void update(int l, int r) {
  for (int i = r; i >= l; --i) {
    if (i + a[i] > n) {
      nex[i] = 0;
      c[i] = 1;
      continue;
    }
    if ((nex[i + a[i]] == 0) || (g[nex[i + a[i]]] > g[i])) {
      nex[i] = i + a[i];
      c[i] = 1;
    } else {
      nex[i] = nex[i + a[i]];
      c[i] = c[i + a[i]] + 1;
    }
  }
}
int main(void) {
  scanf("%d %d", &n, &m);
  int p = (int)floor(sqrt((double)n));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    g[i] = i / p;
  }
  update(1, n);
  for (int i = 1; i <= m; ++i) {
    int flag;
    scanf("%d", &flag);
    if (flag == 0) {
      int j, k;
      scanf("%d %d", &j, &k);
      a[j] = k;
      update(j - j % p, j);
    } else {
      int j;
      scanf("%d", &j);
      int ans = 0, pos = 0;
      for (int k = j; k > 0; k = nex[k]) {
        pos = k;
        ans += c[k];
      }
      printf("%d %d\n", pos, ans);
    }
  }
  return 0;
}
