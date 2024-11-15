#include <bits/stdc++.h>
int n;
double x[105], y[105], z[105], X, Y, Z, d, e;
double dist(double a, double b, double c) { return a * a + b * b + c * c; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
    X += x[i];
    Y += y[i];
    Z += z[i];
  }
  X /= n;
  Y /= n;
  Z /= n;
  double P = 0.5;
  for (int i = 0; i < 1000; i++) {
    int f = 0;
    d = dist(X - x[0], Y - y[0], Z - z[0]);
    for (int j = 1; j < n; j++) {
      e = dist(X - x[j], Y - y[j], Z - z[j]);
      if (d < e) {
        d = e;
        f = j;
      }
    }
    X += (x[f] - X) * P;
    Y += (y[f] - Y) * P;
    Z += (z[f] - Z) * P;
    P *= 0.98;
  }
  printf("%.10lf %.10lf %.10lf", X, Y, Z);
}
