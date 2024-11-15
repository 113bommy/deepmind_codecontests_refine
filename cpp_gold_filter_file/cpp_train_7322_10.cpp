#include <bits/stdc++.h>
using namespace std;
const int nn = 100005;
int n, l, s;
int a[nn], b[nn], c[nn], d[nn];
long long s1, s2;
int r1[nn], r2[nn];
bool cmp(int x, int y) { return d[x] < d[y]; }
long long work(int *r) {
  long long u = 0, v = 0, w = 0;
  for (int i = 1; i < n; ++i) d[i] = a[i + 1] - a[i];
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  if (l >= s - 1) {
    for (int i = s + 1; i < n; ++i) b[i - s] = i;
    sort(b + 1, b + n - s, cmp);
    int k = l - s + 1, j = k;
    for (int i = 1; i <= k; ++i) c[b[i]] = 1, u += 2 * d[b[i]];
    v = u;
    w = 0;
    for (int i = 1; i <= k; ++i) {
      if (c[n - i] > 0) {
        u -= d[n - i];
        c[n - i] = -i;
      } else {
        for (; c[b[j]] <= 0 && j; --j)
          ;
        u += d[n - i] - 2 * d[b[j]];
        c[b[j--]] = -i;
      }
      if (u < v) v = u, w = i;
    }
    for (int i = 1; i <= s; ++i) r[i] = s - i + 1;
    j = s;
    for (int i = s + 1; i < n - w; ++i)
      if (c[i] < -w) {
        int ti = i;
        for (++i; c[i] < -w; ++i)
          ;
        r[++j] = i;
        for (int tj = i - 1; tj >= ti; --tj) r[++j] = tj;
      } else
        r[++j] = i;
    for (int i = 0; i <= w; ++i) r[++j] = n - i;
  } else {
    for (int i = 1; i <= l; ++i) r[i] = s - i + 1;
    for (int i = l + 1; i <= s; ++i) r[i] = i - l;
    for (int i = s + 1; i <= n; ++i) r[i] = i;
  }
  return v + a[n] + a[s];
}
int main() {
  scanf("%d%d%d", &n, &l, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (l == 0) {
    if (s == 1) {
      printf("%d\n", a[n]);
      for (int i = 2; i < n; ++i) printf("%d ", i);
      printf("%d\n", n);
    } else
      puts("-1");
    return 0;
  }
  if (l == n - 1) {
    if (s == n) {
      printf("%d\n", a[n]);
      for (int i = n - 1; i > 1; --i) printf("%d ", i);
      puts("1");
    } else
      puts("-1");
    return 0;
  }
  s1 = work(r1);
  l = n - 1 - l;
  s = n + 1 - s;
  reverse(a + 1, a + n + 1);
  for (int i = n; i; --i) a[i] = a[1] - a[i];
  s2 = work(r2);
  if (s1 < s2) {
    printf("%I64d\n", s1);
    for (int i = 2; i < n; ++i) printf("%d ", r1[i]);
    printf("%d\n", r1[n]);
  } else {
    printf("%I64d\n", s2);
    for (int i = 2; i < n; ++i) printf("%d ", n - r2[i] + 1);
    printf("%d\n", n - r2[n] + 1);
  }
  return 0;
}
