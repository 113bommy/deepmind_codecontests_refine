#include <bits/stdc++.h>
using namespace std;
typedef long long int arr[262144 << 1];
arr aa, ff;
long long int *f = aa + 1;
long long int *g;
struct Node {
  Node *le, *ri;
  long long int del, sum, base;
  Node() : le(0), ri(0), del(0), sum(0), base(0) {}
} * A, *B;
Node *buildtree(int l, int r) {
  Node *ret = new Node();
  if (l == r) {
    ret->base = g[l];
    ret->sum = g[l] * ff[l] % 1000000000;
  } else {
    int m = l + r >> 1;
    ret->le = buildtree(l, m);
    ret->ri = buildtree(m + 1, r);
    ret->base = (ret->le->base + ret->ri->base) % 1000000000;
    ret->sum = (ret->le->sum + ret->ri->sum) % 1000000000;
  }
  return ret;
}
inline void up(Node *nd) { nd->sum = (nd->le->sum + nd->ri->sum) % 1000000000; }
inline void del1(Node *nd, int dd) {
  nd->del = (nd->del + dd) % 1000000000;
  nd->sum = (nd->sum + dd * nd->base) % 1000000000;
}
inline void down(Node *nd) {
  if (nd->del) {
    del1(nd->le, nd->del);
    del1(nd->ri, nd->del);
    nd->del = 0;
  }
}
int Xl, Xr;
long long int Xv;
void cha(Node *nd, int l, int r) {
  if (l == r) {
    nd->sum = Xv * nd->base % 1000000000;
    return;
  }
  int m = l + r >> 1;
  down(nd);
  if (Xl <= m)
    cha(nd->le, l, m);
  else
    cha(nd->ri, m + 1, r);
  up(nd);
}
void jia(Node *nd, int l, int r) {
  if (l > Xr || r < Xl) return;
  if (l >= Xl && r <= Xr) {
    del1(nd, Xv);
    return;
  }
  int m = l + r >> 1;
  down(nd);
  jia(nd->le, l, m);
  jia(nd->ri, m + 1, r);
  up(nd);
}
long long int quer(Node *nd, int l, int r) {
  if (l > Xr || r < Xl) return 0;
  if (l >= Xl && r <= Xr) return nd->sum;
  int m = l + r >> 1;
  down(nd);
  return quer(nd->le, l, m) + quer(nd->ri, m + 1, r);
}
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  f[-1] = 1;
  f[0] = 0;
  for (i = 1; i <= n + 2; i++) f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
  for (i = 1; i <= n; i++) scanf("%d", ff + i);
  g = f;
  A = buildtree(1, n);
  g = f - 1;
  B = buildtree(1, n);
  for (i = -1; i <= n + 2; i++)
    ff[i] = (f[i] == 0 ? 0 : (i & 1 ? f[i] : 1000000000 - f[i]));
  int cmd;
  long long int ans;
  for (i = 1; i <= m; i++) {
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d%I64d", &Xl, &Xv);
      cha(A, 1, n);
      cha(B, 1, n);
    }
    if (cmd == 2) {
      scanf("%d%d", &Xl, &Xr);
      ans = (ff[Xl - 2] * quer(A, 1, n) + ff[Xl - 1] * quer(B, 1, n)) %
            1000000000;
      printf("%I64d\n", ans);
    }
    if (cmd == 3) {
      scanf("%d%d%I64d", &Xl, &Xr, &Xv);
      jia(A, 1, n);
      jia(B, 1, n);
    }
  }
  return 0;
}
