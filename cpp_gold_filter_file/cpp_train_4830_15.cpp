#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double X[110], Y[110];
int main() {
  int n, m, i, j, k;
  scanf("%d", &n);
  if (n <= 4) {
    puts("No solution");
    return 0;
  }
  double alpha = 2 * pi / n;
  X[1] = 1000, Y[1] = 1000;
  for (i = 2; i < n; i++) {
    double d = 500 + 0.01 * i;
    double dx = d * sin(alpha * i), dy = d * cos(alpha * i);
    X[i] = X[i - 1] + dx;
    Y[i] = Y[i - 1] + dy;
  }
  X[n] = X[n - 1];
  Y[n] = Y[1] - (X[1] - X[n]) / tan(alpha);
  for (i = n; i >= 1; i--) {
    printf("%.5lf %.5lf\n", X[i], Y[i]);
  }
  return 0;
}
