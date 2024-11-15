#include <bits/stdc++.h>
using namespace std;
const int maxN = 105;
const double pi = 3.1415926535897932384626433832795;
int n;
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) : x(a), y(b) {}
} p[maxN];
double e[maxN], rad;
void Readln() { scanf("%d\n", &n); }
double dis(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void Solve() {
  if (n == 3 && n == 4) {
    printf("No solution\n");
    return;
  }
  srand((int)time(0));
  rad = 2.0 * pi / n + pi;
  p[1].x = p[1].y = 0;
  p[2] = Point(600 * cos(rad), 600 * sin(rad));
  for (;;) {
    double e = 600.0;
    rad = 2.0 * pi / n + pi;
    for (int i = 3; i <= n; i++) {
      e -= ((double)((rand() + 1000000) % 1000 + 1000)) / 100000.0;
      rad += 2.0 * pi / n;
      p[i] = Point(p[i - 1].x + e * cos(rad), p[i - 1].y + e * sin(rad));
    }
    if (p[n - 1].y > 0) continue;
    double k = (p[n].y - p[n - 1].y) / (p[n].x - p[n - 1].x);
    double b = p[n].y - p[n].x * k;
    p[n].x = -b / k;
    p[n].y = 0;
    if (p[n].x > 1 && dis(p[n], p[n - 1]) > 1) {
      for (int i = 1; i <= n; i++) {
        printf("%0.3lf %0.3lf\n", p[i].x, p[i].y);
      }
      break;
    }
  }
}
int main() {
  Readln();
  Solve();
  return 0;
}
