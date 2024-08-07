#include <bits/stdc++.h>
using namespace std;
double x[101010], y[101010];
double maxn[101010], minn[101010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &maxn[i]);
  for (int i = 1; i <= n; i++) scanf("%lf", &minn[i]);
  for (int i = n - 1; i >= 1; i--) minn[i] += minn[i + 1];
  double resx = 1, resy = 1, getx = 0, gety = 0;
  maxn[0] = 0;
  bool key = false;
  for (int i = 1; i < n; i++) {
    maxn[i] += maxn[i - 1];
    double k1 = maxn[i];
    double k2 = minn[i];
    double a = 0, b = 0, c = 0;
    a += 1;
    b += minn[i + 1] - maxn[i] - 1;
    c += maxn[i];
    double det = b * b - 4 * a * c;
    if (det < 0 && det > -0.1) {
      det = 0;
    }
    double ans1 = (-b + sqrt(det)) / (2 * a);
    double ans2 = (-b - sqrt(det)) / (2 * a);
    x[i] = ans1;
    y[i] = ans2;
  }
  y[n] = x[n] = 1;
  for (int i = n; i >= 1; i--) {
    x[i] = x[i] - x[i - 1];
    y[i] -= y[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    printf("%.8f", y[i]);
    if (i == n)
      printf("\n");
    else
      printf(" ");
  }
  for (int i = 1; i <= n; i++) {
    printf("%.8f", x[i]);
    if (i == n)
      printf("\n");
    else
      printf(" ");
  }
}
