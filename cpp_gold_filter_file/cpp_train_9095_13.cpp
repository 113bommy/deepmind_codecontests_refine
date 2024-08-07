#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1), eps = 0.5;
const int N = 3e6 + 6;
struct cp {
  double x, y;
  cp(double X = 0, double Y = 0) { x = X, y = Y; }
};
cp operator+(cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }
cp operator-(cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }
cp operator*(cp a, cp b) {
  return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
cp a[N], t[N];
int tr[N];
int n, tn, m;
int f[N], g[N], h[N];
void mtr(int n) {
  int l(0);
  for (int t = n; t > 1; t >>= 1) l++;
  for (int i = 0, t, j; i < n; i++) {
    for (tr[i] = j = 0, t = i; j < l; j++, t >>= 1)
      tr[i] = (tr[i] << 1) + (t & 1);
  }
}
void dft(int n, int sg) {
  for (int i = 0; i < n; i++) t[tr[i]] = a[i];
  for (int i = 2; i <= n; i += i) {
    int h = i >> 1;
    for (int j = 0; j < h; j++) {
      cp w(cos(j * pi * sg / h), sin(j * pi * sg / h));
      for (int k = j; k < n; k += i) {
        cp u = t[k], v = t[k + h] * w;
        t[k] = u + v, t[k + h] = u - v;
      }
    }
  }
  for (int i = 0; i < n; i++) a[i] = t[i];
}
int main() {
  scanf("%d%d", &n, &m);
  for (tn = 1; tn <= m + m; tn += tn)
    ;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    a[x].x = 1, f[x] = 1;
  }
  mtr(tn);
  dft(tn, 1);
  for (int i = 0; i < tn; i++) a[i] = a[i] * a[i];
  dft(tn, -1);
  for (int i = 1; i <= m; i++) g[i] = a[i].x > eps;
  int ok(1);
  h[0] = 0;
  for (int i = 1; i <= m && ok; i++)
    if (g[i] && !f[i])
      ok = 0;
    else if (!g[i] && f[i])
      h[++h[0]] = i;
  if (!ok) return puts("NO"), 0;
  printf("YES\n%d\n", h[0]);
  for (int i = 1; i < h[0]; i++) printf("%d ", h[i]);
  printf("%d\n", h[h[0]]);
  return 0;
}
