#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    n++;
    int x[n], y[n], z[n], vs, vp, xp, yp, zp;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    cin >> vp >> vs;
    cin >> xp >> yp >> zp;
    double lo = 0, hi = 1.0e10, xf, yf, zf;
    bool found = 0;
    for (int it = 0; it < 100; it++) {
      double mid = (lo + hi) / 2;
      double S = 0, L = mid * vs;
      bool ok = 0;
      for (int i = 1; i < n; i++) {
        double D = sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) +
                        (y[i] - y[i - 1]) * (y[i] - y[i - 1]) +
                        (z[i] - z[i - 1]) * (z[i] - z[i - 1]));
        if (S + D + 1e-8 < L)
          S += D;
        else {
          xf = x[i - 1] + (L - S) * (x[i] - x[i - 1]) / D;
          yf = y[i - 1] + (L - S) * (y[i] - y[i - 1]) / D;
          zf = z[i - 1] + (L - S) * (z[i] - z[i - 1]) / D;
          double T = sqrt((xf - xp) * (xf - xp) + (yf - yp) * (yf - yp) +
                          (zf - zp) * (zf - zp)) /
                     vp;
          if (T > mid)
            lo = mid;
          else {
            hi = mid;
            found = 1;
          }
          ok = 1;
          break;
        }
      }
      if (!ok) hi = mid;
    }
    if (found) {
      cout << "YES" << endl;
      printf("%.10lf\n", lo);
      printf("%.10lf %.10lf %.10lf\n", xf, yf, zf);
    } else
      cout << "NO" << endl;
  }
  return 0;
}
