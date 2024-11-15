#include <bits/stdc++.h>
using namespace std;
const int maxn = 200050;
int n, m;
int now = 0, l[maxn] = {0}, r[maxn] = {0}, c[maxn] = {0};
long long sum[maxn] = {0}, sum0[maxn] = {0};
void build(int x, int ll, int rr) {
  if (ll == rr) {
    c[x] = ll;
    return;
  }
  int mid = (ll + rr) >> 1;
  if (ll <= mid) build(l[x] = ++now, ll, mid);
  if (rr > mid) build(r[x] = ++now, mid + 1, rr);
}
void down(int x, int s) {
  sum0[l[x]] += sum0[x], c[l[x]] = c[x];
  sum0[r[x]] += sum0[x], c[r[x]] = c[x];
  sum[x] += sum0[x] * s;
  sum0[x] = c[x] = 0;
}
void update(int x, int ls, int rs) {
  if (c[l[x]] == c[r[x]]) c[x] = c[l[x]];
  sum[x] = sum[l[x]] + sum[r[x]] + sum0[l[x]] * ls + sum0[r[x]] * rs;
}
void change(int x, int ll, int rr, int a, int b, int cc) {
  int mid = (ll + rr) >> 1;
  if (a <= ll && rr <= b && c[x])
    sum0[x] += abs(c[x] - cc), c[x] = cc;
  else {
    if (c[x]) down(x, rr - ll + 1);
    if (a <= mid) change(l[x], ll, mid, a, b, cc);
    if (b > mid) change(r[x], mid + 1, rr, a, b, cc);
    update(x, mid - ll + 1, rr - mid);
  }
}
long long query(int x, int ll, int rr, int a, int b) {
  int mid = (ll + rr) >> 1;
  if (a <= ll && rr <= b)
    return sum[x] + sum0[x] * (rr - ll + 1);
  else {
    long long s = 0;
    if (c[x]) down(x, rr - ll + 1);
    if (a <= mid) s += query(l[x], ll, mid, a, b);
    if (b > mid) s += query(r[x], mid + 1, rr, a, b);
    return s;
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  build(++now, 1, n);
  while (m--) {
    int o, ll, rr, x;
    scanf("%d%d%d", &o, &ll, &rr);
    if (o == 1) {
      scanf("%d", &x);
      change(1, 1, n, ll, rr, x);
    } else
      printf("%I64d\n", query(1, 1, n, ll, rr));
  }
  return 0;
}
