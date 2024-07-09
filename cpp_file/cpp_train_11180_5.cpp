#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200, siz = 2, mod = 1000000000;
long long num[maxn], fib[maxn];
struct Matrix {
  long long a[siz][siz];
  Matrix(const bool unit = false) {
    for (int i = 0; i < siz; i++)
      for (int j = 0; j < siz; j++) a[i][j] = 0;
    if (unit) a[0][0] = a[0][1] = a[1][0] = 1;
  }
} Fib[maxn];
struct node {
  Matrix ans;
  long long add;
  int l, r, siz;
} tr[maxn << 2];
Matrix operator+(Matrix a, Matrix b) {
  Matrix ret(false);
  for (int i = 0; i < siz; i++)
    for (int j = 0; j < siz; j++) ret.a[i][j] = (a.a[i][j] + b.a[i][j]) % mod;
  return ret;
}
Matrix operator*(Matrix a, Matrix b) {
  Matrix ret(false);
  for (int i = 0; i < siz; i++)
    for (int j = 0; j < siz; j++)
      for (int k = 0; k < siz; k++)
        ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
  return ret;
}
Matrix pow(Matrix a, int n) { return Fib[n] * a; }
void pushup(int t) {
  tr[t].ans = tr[(t << 1)].ans + pow(tr[(t << 1 | 1)].ans, tr[(t << 1)].siz);
}
void pushdown(int t) {
  if (tr[t].add) {
    tr[(t << 1)].add = (tr[(t << 1)].add + tr[t].add) % mod;
    tr[(t << 1 | 1)].add = (tr[(t << 1 | 1)].add + tr[t].add) % mod;
    tr[(t << 1)].ans.a[0][0] =
        (tr[(t << 1)].ans.a[0][0] + fib[tr[(t << 1)].siz - 1] * tr[t].add) %
        mod;
    if (tr[(t << 1)].siz > 1)
      tr[(t << 1)].ans.a[0][1] =
          (tr[(t << 1)].ans.a[0][1] + fib[tr[(t << 1)].siz - 2] * tr[t].add) %
          mod;
    tr[(t << 1 | 1)].ans.a[0][0] = (tr[(t << 1 | 1)].ans.a[0][0] +
                                    fib[tr[(t << 1 | 1)].siz - 1] * tr[t].add) %
                                   mod;
    if (tr[(t << 1 | 1)].siz > 1)
      tr[(t << 1 | 1)].ans.a[0][1] =
          (tr[(t << 1 | 1)].ans.a[0][1] +
           fib[tr[(t << 1 | 1)].siz - 2] * tr[t].add) %
          mod;
    tr[t].add = 0;
  }
}
void build(int l, int r, int t) {
  int mid = (l + r) >> 1;
  tr[t].l = l;
  tr[t].r = r;
  tr[t].siz = (r - l + 1);
  if (l == r) {
    tr[t].ans.a[0][0] = num[mid];
    tr[t].ans.a[0][1] = 0;
    tr[t].add = 0;
    return;
  }
  build(l, mid, (t << 1));
  build(mid + 1, r, (t << 1 | 1));
  pushup(t);
}
void modify(int l, int r, int x, int t) {
  int mid = (l + r) >> 1;
  if (l == r) {
    tr[t].ans.a[0][0] = num[mid];
    tr[t].ans.a[0][1] = 0;
    tr[t].add = 0;
    return;
  }
  pushdown(t);
  if (x <= mid)
    modify(l, mid, x, (t << 1));
  else
    modify(mid + 1, r, x, (t << 1 | 1));
  pushup(t);
}
void add(int ql, int qr, int l, int r, long long num, int t) {
  int mid = (l + r) >> 1;
  pushdown(t);
  if (ql == l && r == qr) {
    tr[t].add = (tr[t].add + num) % mod;
    tr[t].ans.a[0][0] = (tr[t].ans.a[0][0] + fib[tr[t].siz - 1] * num) % mod;
    if (tr[t].siz > 1)
      tr[t].ans.a[0][1] = (tr[t].ans.a[0][1] + fib[tr[t].siz - 2] * num) % mod;
    return;
  }
  if (qr <= mid)
    add(ql, qr, l, mid, num, (t << 1));
  else if (ql > mid)
    add(ql, qr, mid + 1, r, num, (t << 1 | 1));
  else
    add(ql, mid, l, mid, num, (t << 1)),
        add(mid + 1, qr, mid + 1, r, num, (t << 1 | 1));
  pushup(t);
}
Matrix query(int ql, int qr, int l, int r, int t) {
  int mid = (l + r) >> 1;
  pushdown(t);
  if (ql == l && r == qr) return tr[t].ans;
  if (qr <= mid)
    return query(ql, qr, l, mid, (t << 1));
  else if (ql > mid)
    return query(ql, qr, mid + 1, r, (t << 1 | 1));
  else
    return query(ql, mid, l, mid, (t << 1)) +
           pow(query(mid + 1, qr, mid + 1, r, (t << 1 | 1)), mid - ql + 1);
}
int main() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i < maxn; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  Matrix x(true);
  Fib[1] = x;
  for (int i = 2; i < maxn; i++) Fib[i] = Fib[i - 1] * Fib[1];
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; i++) scanf("%lld", &num[i]);
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      num[x] = y;
      modify(1, n, x, 1);
    }
    if (opt == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(l, r, 1, n, 1).a[0][0]);
    }
    if (opt == 3) {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d);
      add(l, r, 1, n, d, 1);
    }
  }
  return 0;
}
