#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[300000], sum[300000], a[300000], lazy[4 * 300000];
struct node {
  int Sum1, Sum2, siz;
} W[4 * 300000];
node operator+(node a, node b) {
  node c;
  c.Sum1 = (a.Sum1 + 1ll * f[a.siz - 1] * b.Sum2 % 1000000000 +
            1ll * (a.siz >= 2) * f[max(a.siz - 2, 0)] * b.Sum1 % 1000000000) %
           1000000000;
  c.Sum2 = (a.Sum2 + 1ll * f[a.siz] * b.Sum2 % 1000000000 +
            1ll * f[a.siz - 1] * b.Sum1 % 1000000000) %
           1000000000;
  c.siz = a.siz + b.siz;
  return c;
}
void Init() {
  f[0] = 1, f[1] = 1;
  sum[0] = 1;
  for (int i = 2; i <= 300000 - 5; i++)
    f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
  for (int i = 1; i <= 300000 - 5; i++)
    sum[i] = (sum[i - 1] + f[i]) % 1000000000;
  return;
}
void pushdown(int x) {
  if (lazy[x]) {
    lazy[(x << 1)] = (lazy[(x << 1)] + lazy[x]) % 1000000000;
    lazy[(x << 1 | 1)] = (lazy[(x << 1 | 1)] + lazy[x]) % 1000000000;
    if (W[(x << 1)].siz)
      W[(x << 1)].Sum1 =
          (W[(x << 1)].Sum1 +
           1ll * lazy[x] * (sum[W[(x << 1)].siz - 1]) % 1000000000) %
          1000000000;
    W[(x << 1)].Sum2 =
        (W[(x << 1)].Sum2 +
         1ll * lazy[x] * (sum[W[(x << 1)].siz] - sum[0]) % 1000000000) %
        1000000000;
    if (W[(x << 1 | 1)].siz)
      W[(x << 1 | 1)].Sum1 =
          (W[(x << 1 | 1)].Sum1 +
           1ll * lazy[x] * (sum[W[(x << 1 | 1)].siz - 1]) % 1000000000) %
          1000000000;
    W[(x << 1 | 1)].Sum2 =
        (W[(x << 1 | 1)].Sum2 +
         1ll * lazy[x] * (sum[W[(x << 1 | 1)].siz] - sum[0]) % 1000000000) %
        1000000000;
    lazy[x] = 0;
    return;
  }
}
void build(int x, int l, int r) {
  W[x].siz = (r - l + 1);
  if (l == r) {
    W[x].Sum1 = a[l] * f[0] % 1000000000;
    W[x].Sum2 = a[l] * f[1] % 1000000000;
    return;
  }
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  W[x] = W[(x << 1)] + W[(x << 1 | 1)];
  return;
}
void update(int x, int l, int r, int pos, int k) {
  if (l == r) {
    W[x].Sum1 = k * f[0] % 1000000000;
    W[x].Sum2 = k * f[1] % 1000000000;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update((x << 1), l, mid, pos, k);
  else
    update((x << 1 | 1), mid + 1, r, pos, k);
  W[x] = W[(x << 1)] + W[(x << 1 | 1)];
  return;
}
void modify(int x, int l, int r, int ll, int rr, int k) {
  if (l == ll && r == rr) {
    lazy[x] = (lazy[x] + k) % 1000000000;
    W[x].Sum1 =
        (W[x].Sum1 + lazy[x] * (sum[W[x].siz - 1]) % 1000000000) % 1000000000;
    W[x].Sum2 = (W[x].Sum2 + lazy[x] * (sum[W[x].siz] - sum[0]) % 1000000000) %
                1000000000;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (rr <= mid)
    modify((x << 1), l, mid, ll, rr, k);
  else if (ll > mid)
    modify((x << 1 | 1), mid + 1, r, ll, rr, k);
  else
    modify((x << 1), l, mid, ll, mid, k),
        modify((x << 1 | 1), mid + 1, r, mid + 1, rr, k);
  W[x] = W[(x << 1)] + W[(x << 1 | 1)];
}
node query(int x, int l, int r, int ll, int rr) {
  if (l == ll && r == rr) return W[x];
  pushdown(x);
  int mid = (l + r) >> 1;
  if (rr <= mid)
    return query((x << 1), l, mid, ll, rr);
  else if (ll > mid)
    return query((x << 1 | 1), mid + 1, r, ll, rr);
  else
    return query((x << 1), l, mid, ll, mid) +
           query((x << 1 | 1), mid + 1, r, mid + 1, rr);
}
int main() {
  scanf("%d%d", &n, &m);
  Init();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int op, l, r, d;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) update(1, 1, n, l, r);
    if (op == 2) printf("%d\n", query(1, 1, n, l, r).Sum1 % 1000000000);
    if (op == 3) {
      scanf("%d", &d);
      modify(1, 1, n, l, r, d);
    }
  }
  return 0;
}
