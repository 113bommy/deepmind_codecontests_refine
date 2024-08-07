#include <bits/stdc++.h>
using namespace std;
const int n1 = 50010;
struct ww {
  struct w1 {
    int l, r, s;
  } a[2];
  struct w2 {
    int s, n;
  } l[2], r[2];
  int s, cov;
} tr[n1 * 4], an[40];
int i, j, k, n, m, x, y, z, buff, d[n1], re;
inline void read(int &x) {
  char p = getchar();
  int f = 1;
  for (; p < '0' || p > '9'; p = getchar())
    if (p == '-') f = -1;
  for (x = 0; p >= '0' && p <= '9'; x = x * 10 + p - 48, p = getchar())
    ;
  x *= f;
}
inline bool Y(int a, int b) { return buff ? a > b : a < b; }
inline void updata(ww &x, ww y, ww z) {
  x.s = y.s + z.s;
  int i;
  for (i = 0; i <= 1; i++) {
    buff = i;
    x.l[i] = y.l[i];
    x.r[i] = z.r[i];
    if (Y(y.s + z.l[i].s, x.l[i].s))
      x.l[i].s = y.s + z.l[i].s, x.l[i].n = z.l[i].n;
    if (Y(z.s + y.r[i].s, x.r[i].s))
      x.r[i].s = z.s + y.r[i].s, x.r[i].n = y.r[i].n;
    if (Y(y.a[i].s, z.a[i].s))
      x.a[i] = y.a[i];
    else
      x.a[i] = z.a[i];
    if (Y(y.r[i].s + z.l[i].s, x.a[i].s))
      x.a[i].s = y.r[i].s + z.l[i].s, x.a[i].l = y.r[i].n, x.a[i].r = z.l[i].n;
  }
}
inline void cover(ww &x) {
  x.s *= -1, x.cov ^= 1;
  swap(x.a[0], x.a[1]), swap(x.l[0], x.l[1]), swap(x.r[0], x.r[1]);
  int i;
  for (i = 0; i <= 1; i++) x.a[i].s *= -1, x.l[i].s *= -1, x.r[i].s *= -1;
}
inline void renew(int q) {
  if (tr[q].cov) cover(tr[q * 2]), cover(tr[q * 2 + 1]);
  tr[q].cov = 0;
}
inline void C(ww &x, int y, int z) {
  int i;
  x.s = y;
  for (i = 0; i <= 1; i++) {
    x.a[i].s = x.l[i].s = x.r[i].s = y;
    x.a[i].l = x.a[i].r = x.l[i].n = x.r[i].n = z;
  }
}
void build(int q, int x, int y) {
  int mid = (x + y) / 2;
  if (x == y) {
    C(tr[q], d[x], x);
    return;
  }
  build(q * 2, x, mid);
  build(q * 2 + 1, mid + 1, y);
  updata(tr[q], tr[q * 2], tr[q * 2 + 1]);
}
void change(int q, int x, int y, int k, int t) {
  int mid = (x + y) / 2;
  if (x == y) {
    C(tr[q], t, x);
    return;
  }
  renew(q);
  if (k <= mid)
    change(q * 2, x, mid, k, t);
  else
    change(q * 2 + 1, mid + 1, y, k, t);
  updata(tr[q], tr[q * 2], tr[q * 2 + 1]);
}
void work(int q, int x, int y, int l, int r, int t) {
  int mid = (x + y) / 2;
  if (l <= x && y <= r) {
    if (t > 0) {
      if (an[t].s == 1 << 28)
        an[t] = tr[q];
      else
        an[0] = an[t], updata(an[t], an[0], tr[q]);
    } else
      cover(tr[q]);
    return;
  }
  renew(q);
  if (l <= mid) work(q * 2, x, mid, l, r, t);
  if (r > mid) work(q * 2 + 1, mid + 1, y, l, r, t);
  updata(tr[q], tr[q * 2], tr[q * 2 + 1]);
}
int main() {
  read(n);
  for (i = 1; i <= n; i++) read(d[i]);
  build(1, 1, n);
  read(m);
  for (i = 1; i <= m; i++) {
    read(k), read(x), read(y);
    if (k) {
      read(z);
      re = 0;
      for (j = 1; j <= z; j++) {
        an[j].s = 1 << 28;
        work(1, 1, n, x, y, j);
        work(1, 1, n, an[j].a[1].l, an[j].a[1].r, 0);
        if (an[j].a[1].s > 0)
          re += an[j].a[1].s;
        else
          break;
      }
      for (j = min(j, z); j; j--) work(1, 1, n, an[j].a[1].l, an[j].a[1].r, 0);
      printf("%d\n", re);
    } else
      change(1, 1, n, x, y);
  }
  return 0;
}
