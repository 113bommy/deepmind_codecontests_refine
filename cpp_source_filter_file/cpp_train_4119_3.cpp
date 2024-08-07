#include <bits/stdc++.h>
using namespace std;
int n, x;
double p[233333];
struct mtx {
  int n;
  double s[130][130];
};
mtx operator*(mtx a, mtx b) {
  mtx Now;
  Now.n = a.n;
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++) {
      double rp = 0;
      for (int k = 0; k < a.n; k++) rp = rp + a.s[i][k] * b.s[k][j];
      Now.s[i][j] = rp;
    }
  }
  return Now;
}
mtx Read(int n) {
  mtx Now;
  Now.n = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) Now.s[i][j] = i == j;
  }
  return Now;
}
mtx quickpow(mtx a, long long b) {
  mtx Now = Read(a.n);
  while (b) {
    if (b & 1) Now = Now * a;
    a = a * a;
    b >>= 1;
  }
  return Now;
}
mtx t;
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i <= x; i++) scanf("%lf", p + i);
  int tt = 1;
  while (tt <= x) tt <<= 2;
  t.n = x = tt;
  for (int i = 1; i < x; i++) {
    for (int j = 0; j < x; j++) t.s[i][j] = p[i ^ j];
  }
  mtx r = quickpow(t, n);
  printf("%.10lf\n", 1 - r.s[0][0]);
  return 0;
}
