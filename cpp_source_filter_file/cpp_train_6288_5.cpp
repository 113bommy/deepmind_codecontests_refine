#include <bits/stdc++.h>
using namespace std;
struct dara {
  double x, y;
} a[310];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  double fn = -INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double mx = -INT_MAX, mn = INT_MAX;
      for (int k = 1; k <= n; k++) {
        if (i != k && i != j) {
          double tmp =
              0.5 * (a[i].x * (a[j].y - a[k].y) + a[j].x * (a[k].y - a[i].y) +
                     a[k].x * (a[i].y - a[j].y));
          mx = max(mx, tmp);
          mn = min(mn, tmp);
        }
      }
      fn = max(fn, mx + (-1 * mn));
    }
  }
  printf("%.9lf\n", fn);
}
