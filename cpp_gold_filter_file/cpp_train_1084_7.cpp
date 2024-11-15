#include <bits/stdc++.h>
struct cube {
  double x1, x2, y1, y2, a, v;
} c[100];
void swap(double &a, double &b) {
  double t = a;
  a = b;
  b = t;
}
double X, Y, V;
void cal(int i) {
  double tx = (c[i].x1 + c[i].x2) / 2, ty = (c[i].y1 + c[i].y2) / 2,
         tv = c[i].v;
  X = (V * X + tv * tx) / (V + tv), Y = (V * Y + tv * ty) / (V + tv), V += tv;
}
bool J(int i) {
  return X >= c[i].x1 && X <= c[i].x2 && Y >= c[i].y1 && Y <= c[i].y2;
}
int main() {
  int n, i, j, ans;
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &c[i].x1, &c[i].y1, &c[i].x2, &c[i].y2);
      if (c[i].x1 > c[i].x2) swap(c[i].x1, c[i].x2);
      if (c[i].y1 > c[i].y2) swap(c[i].y1, c[i].y2);
      c[i].a = sqrt(((c[i].x1 - c[i].x2) * (c[i].x1 - c[i].x2) +
                     (c[i].y1 - c[i].y2) * (c[i].y1 - c[i].y2)) /
                    2);
      c[i].v = c[i].a * c[i].a * c[i].a;
    }
    ans = 1;
    bool f = 1;
    for (i = 1; i < n; i++) {
      X = (c[i].x1 + c[i].x2) / 2, Y = (c[i].y1 + c[i].y2) / 2, V = c[i].v;
      for (j = i - 1; j >= 0; j--) {
        if (J(j))
          cal(j);
        else {
          f = 0;
          break;
        }
      }
      if (f)
        ans++;
      else
        break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
