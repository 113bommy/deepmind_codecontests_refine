#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int T, m, n, a[maxn], ti[maxn], ri[maxn];
;
int d, p, rem, rem0;
bool whe[maxn];
int main() {
  int i, j;
  scanf("%d", &T);
  while (T--) {
    d = p = rem = 0;
    scanf("%d%d", &m, &n);
    for (i = 1; i <= n; i++) whe[i] = 0;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i < m; i++) {
      scanf("%d%d", &ti[i], &ri[i]);
      if (!d && ri[i]) rem0 = rem, d = i;
      if (ti[i]) {
        a[ti[i]]--;
        if (!a[ti[i]] && !d) p = ti[i];
      } else
        rem++;
    }
    if (!p && d) {
      for (i = m - 1; i >= d; i--) whe[ti[i]] = 1;
      for (i = 1; i <= n; i++)
        if (!whe[i] && (a[i] < a[p])) p = i;
      rem -= a[p];
      for (i = 1; i <= n; i++)
        if (!whe[i] && a[i] <= rem0) a[i] = 0;
    }
    for (i = 1; i <= n; i++) printf("%c", a[i] <= rem ? 'Y' : 'N');
    printf("\n");
  }
  return 0;
}
