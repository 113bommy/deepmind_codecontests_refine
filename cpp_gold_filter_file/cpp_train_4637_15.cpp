#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const long double eps = 1e-10;
long double x[maxn], y[maxn], z[maxn], reach_t[maxn];
long double vs, vp, px, py, pz, ansx, ansy, ansz;
int n;
inline long double calc_dist(long double x, long double y, long double z,
                             long double x2, long double y2, long double z2) {
  return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2) + (z - z2) * (z - z2));
}
inline long double get_part(long double l, long double r, long double pt) {
  return l * (1.0 - pt) + r * pt;
}
inline int dcmp(long double v) {
  if (fabsl(v) < eps) return 0;
  return v > 0.0 ? 1 : -1;
}
inline bool check(long double d, int pos) {
  long double pt = (d - reach_t[pos - 1]) / (reach_t[pos] - reach_t[pos - 1]);
  long double sx = get_part(x[pos - 1], x[pos], pt);
  long double sy = get_part(y[pos - 1], y[pos], pt);
  long double sz = get_part(z[pos - 1], z[pos], pt);
  ansx = sx, ansy = sy, ansz = sz;
  return dcmp(calc_dist(sx, sy, sz, px, py, pz) / vp - d) <= 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <= n; i++) cin >> x[i] >> y[i] >> z[i];
  cin >> vp >> vs >> px >> py >> pz;
  reach_t[0] = 0.0;
  for (int i = 1; i <= n; i++)
    reach_t[i] = reach_t[i - 1] +
                 calc_dist(x[i - 1], y[i - 1], z[i - 1], x[i], y[i], z[i]) / vs;
  long double mint = -1.0;
  for (int i = 1; i <= n; i++) {
    long double l = reach_t[i - 1], r = reach_t[i];
    while (r - l > eps) {
      long double mid = (l + r) / 2.0;
      if (check(mid, i))
        r = mid;
      else
        l = mid;
    }
    if (check(r, i)) {
      mint = r;
      break;
    } else if (check(reach_t[i - 1], i)) {
      mint = reach_t[i - 1];
      break;
    }
  }
  if (mint < 0)
    cout << "NO\n";
  else {
    cout << "YES\n";
    cout << fixed << setprecision(15) << mint << '\n';
    cout << fixed << setprecision(15) << ansx << ' ' << ansy << ' ' << ansz
         << '\n';
  }
  return 0;
}
