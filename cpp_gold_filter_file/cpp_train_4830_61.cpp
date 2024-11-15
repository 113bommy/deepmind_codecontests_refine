#include <bits/stdc++.h>
const int MAXN = 105;
const double PLEN = 100;
const double DLEN = 0.002;
int n;
double X[MAXN];
double Y[MAXN];
void init() { scanf("%d", &n); }
void solve() {
  if (n <= 4) {
    printf("No solution\n");
    return;
  }
  double x = -PLEN, y = 0;
  for (int i = 0; i < n - 1; ++i) {
    double p = 2 * M_PI * i / n;
    x += cos(p) * (PLEN + i * DLEN);
    y += sin(p) * (PLEN + i * DLEN);
    X[i] = x;
    Y[i] = y;
  }
  double xx = x + y / tan(2 * M_PI / n);
  X[n - 1] = xx;
  Y[n - 1] = 0;
  for (int i = 0; i < n; ++i) printf("%f %f\n", X[i], Y[i]);
}
int main() {
  init();
  solve();
  return 0;
}
