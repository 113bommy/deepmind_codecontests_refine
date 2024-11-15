#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double _x = 0, double _y = 0) { x = _x, y = _y; }
  friend point operator-(const point& A, const point& B) {
    return point(A.x - B.x, A.y - B.y);
  }
  point operator*(double k) { return point(x * k, y * k); }
  double dis() { return sqrt(x * x + y * y); }
} a[105];
int N;
void doit() {
  scanf("%d", &N);
  if (N <= 4) {
    puts("No solution");
    return;
  }
  double A = 2 * acos(-1) / N;
  for (int i = 0; i < N; i++) a[i] = point(cos(i * A), sin(i * A)) * 1e2 * N;
  for (int i = 0; i < N; i++) {
    point u = a[i] - a[(i + N - 1) % N], v = a[(i + 1) % N] - a[(i + 2) % N];
    double k = -rand() % 20 * 1.0 / u.dis();
    a[i] = a[i] - u * k,
    a[(i + 1) % N] = a[(i + 1) % N] - v * (k * u.dis() / v.dis());
  }
  for (int i = 0; i < N; i++) printf("%.9lf %.9lf\n", a[i].x, a[i].y);
}
int main() {
  doit();
  return 0;
}
