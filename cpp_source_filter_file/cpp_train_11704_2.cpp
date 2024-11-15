#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int n, k, p[maxn], b[maxn], d[maxn], whe[maxn] = {0};
int tr[2][maxn] = {0};
long long ans = 0;
inline int lowbit(int x) { return x & (-x); }
void add(int x, int c) {
  while (x <= n) tr[c][x]++, x += lowbit(x);
}
int que(int x, int c) {
  int s = 0;
  while (x) s += tr[c][x], x -= lowbit(x);
  return s;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &p[i]), d[p[i]] = i;
  for (i = 1; i <= n; i++) scanf("%d", &b[i]), whe[b[i]] = 1;
  sort(p + 1, p + 1 + n);
  for (i = 1; i <= n; i++)
    if (whe[p[i]])
      add(d[p[i]], 0);
    else {
      int s = que(d[p[i]], 0), l = 0, r = d[p[i]], mid;
      while (r > l) {
        mid = (l + r) / 2;
        if (que(mid, 0) == s)
          r = mid;
        else
          l = mid + 1;
      }
      ans += d[p[i]] - l - (que(d[p[i]], 1) - que(l, 1));
      l = d[p[i]], r = n;
      while (r > l) {
        mid = (l + r) / 2 + 1;
        if (que(mid, 0) == s)
          l = mid;
        else
          r = mid - 1;
      }
      ans += l - d[p[i]] - (que(l, 1) - que(d[p[i]], 1));
      add(d[p[i]], 1);
    }
  printf("%I64d\n", ans);
  return 0;
}
