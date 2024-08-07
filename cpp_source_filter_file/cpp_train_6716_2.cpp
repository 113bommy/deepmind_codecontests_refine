#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int a[200005], b[200005];
int da[200005], db[200005];
int t[200005], c[200005];
int pos(int d) {
  long long g[200005];
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) {
      g[i] = ((long long)a[d]) * c[i];
    } else {
      g[i] = ((long long)b[d]) * c[i];
    }
  }
  sort(g, g + m);
  long long cs = 0;
  for (int i = 0; i < k; i++) {
    cs += g[i];
  }
  if (cs > s)
    return 0;
  else
    return 1;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    da[i] = i;
    if (i > 0 && a[i - 1] < a[i]) {
      a[i] = a[i - 1];
      da[i] = da[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    db[i] = i;
    if (i > 0 && b[i - 1] < b[i]) {
      b[i] = b[i - 1];
      db[i] = db[i - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &t[i], &c[i]);
  }
  int l = 0, r = m - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (pos(m))
      r = m;
    else
      l = m + 1;
  }
  if (pos(l)) {
    pair<long long, int> g[200005];
    for (int i = 0; i < m; i++) {
      if (t[i] == 1) {
        g[i] = make_pair((((long long)a[l]) * c[i]), (i));
      } else {
        g[i] = make_pair((((long long)b[l]) * c[i]), (i));
      }
    }
    sort(g, g + m);
    printf("%d\n", l + 1);
    for (int i = 0; i < k; i++) {
      if (t[g[i].second] == 1) {
        printf("%d %d\n", g[i].second + 1, da[l] + 1);
      } else {
        printf("%d %d\n", g[i].second + 1, db[l] + 1);
      }
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
