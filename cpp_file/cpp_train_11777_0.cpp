#include <bits/stdc++.h>
using namespace std;
int n, t[100010];
double w, h, e1, e2, po[100010][2];
bool hurd(double v) {
  double l = e1, r = e1, dx = (e1 + e2) / 2, dy = h / 2;
  for (int i = 1; i <= n; i++) {
    double a = (h - po[i][1]) / po[i][1] * (dy / (h - dy)),
           b = (dx + dy / (h - dy) * dx) +
               (-dy / (h - dy)) * (po[i][0] + (h / po[i][1] - 1) * po[i][0]);
    double a1 = v * (t[i] - t[i - 1]), a2 = (dy / (h - dy)) * a1;
    double l1 = l - a1, r1 = r + a1, l2 = (l - a2 - b) / a,
           r2 = (r + a2 - b) / a, l3, r3, l4, r4;
    if (a < 1 - 1e-8) {
      l3 = (a1 + a2 - b) / (a - 1);
      r3 = (-a1 - a2 - b) / (a - 1);
    } else if (a > 1 + 1e-8) {
      l3 = (-a1 - a2 - b) / (a - 1);
      r3 = (a1 + a2 - b) / (a - 1);
    } else {
      if (abs(b) > a1 + a2) return 0;
      l3 = 0, r3 = w;
    }
    l4 = po[i][0] - (w - po[i][0]) * po[i][1] / (h - po[i][1]);
    r4 = po[i][0] + po[i][0] * po[i][1] / (h - po[i][1]);
    l = max(max(max(l1, l2), max(l3, l4)), 0.0);
    r = min(min(min(r1, r2), min(r3, r4)), w);
    if (l > r)
      if (l - r < 1e-8)
        swap(l, r);
      else
        return false;
    dx = po[i][0];
    dy = po[i][1];
  }
  return true;
}
int main() {
  cin >> n >> w >> h >> e1 >> e2;
  for (int i = 1; i <= n; i++) cin >> t[i] >> po[i][0] >> po[i][1];
  if (!hurd(w + 1)) {
    cout << "-1" << endl;
    return 0;
  }
  double l = 0, r = w, mid;
  while ((r - l) / max(1.0, l) > 1e-8) {
    mid = (l + r) / 2;
    if (hurd(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.12f\n", (double)(l + r) / 2);
}
