#include <bits/stdc++.h>
int main() {
  int d[1005], s[1005], i, t, f, mx, m, k;
  scanf("%d %d", &m, &k);
  for (i = 0; i < m; i++) scanf("%d", &d[i]);
  for (i = 0; i < m; i++) scanf("%d", &s[i]);
  f = t = 0;
  for (i = 0; i < m; i++) {
    f += s[i];
    if (i == 0 || mx < s[i]) mx = s[i];
    while (f < d[i]) {
      f += mx;
      t += k;
    }
    f -= d[i];
    t += d[i];
  }
  printf("%d\n", t);
  return 0;
}
