#include <bits/stdc++.h>
using namespace std;
int i, j, k, l[100005], r[100005], q[100005], s, m, n, o;
long long ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= m; i++) scanf("%d%d%d", &l[i], &r[i], &q[i]);
  for (i = 1; i <= k; i++) {
    scanf("%d", &j);
    for (o = 1; o <= m; o++) {
      if (j >= l[o] && j <= r[o]) ans = ans + 1ll * (j - l[o] + q[o]);
    }
    printf("%I64d\n", ans);
    ans = 0;
  }
}
