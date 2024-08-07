#include <bits/stdc++.h>
using namespace std;
long long n, m, h[100005], p[100005], f[100005];
bool check(long long x) {
  int now = 1;
  for (int i = 1; i <= n; i++) {
    long long rest = x - abs(h[i] - p[now]);
    if (rest < 0) continue;
    long long nowp = p[now];
    while ((p[now] <= h[i] || p[now] - nowp <= rest ||
            2 * (p[now] - h[i]) <= rest) &&
           now <= m)
      now++;
    if (now == m + 1) return 1;
  }
  return now == m + 1;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", &h[i]);
  for (int i = 1; i <= m; i++) scanf("%I64d", &p[i]);
  long long l = 0, r = 100000000000;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
