#include <bits/stdc++.h>
using namespace std;
int f[555555], g[555555], pos[555555], i, j, ans, n, a[555555], q, t1, x, y;
void update(int x, int d) {
  while (x <= n) {
    f[x] += d;
    x = x | (x + 1);
  }
}
int count(int x) {
  int ans = 0;
  while (x > 0) {
    ans += f[x];
    x = x & (x + 1);
    x -= 1;
  }
  return ans;
}
int get(int l, int r) {
  if (l > r) return 0;
  return count(r) - count(l - 1);
}
void doit(int p) {
  if (p > 1) {
    if (g[p] != 0) update(p, -g[p]);
    g[p] = 0;
    if (pos[p] < pos[p - 1]) {
      g[p] = 1;
      update(p, g[p]);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for (i = 2; i <= n; ++i)
    if (pos[i] < pos[i - 1]) {
      g[i] = 1;
      update(i, g[i]);
    }
  scanf("%d", &q);
  while (q > 0) {
    q--;
    scanf("%d%d%d", &t1, &x, &y);
    if (t1 == 1) {
      ans = get(x + 1, y) + 1;
      cout << ans << endl;
    } else {
      swap(a[x], a[y]);
      pos[a[x]] = x;
      pos[a[y]] = y;
      for (i = -100; i <= 100; ++i) {
        if (x + i > 0 && x + i <= n) doit(x + i);
        if (y + i > 0 && y + i <= n) doit(y + i);
      }
    }
  }
}
