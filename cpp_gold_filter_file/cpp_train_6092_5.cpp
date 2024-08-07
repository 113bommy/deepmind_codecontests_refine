#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const double PI = 3.141592653589793;
int n, q, t, u, v;
double c[360], s[360];
struct STree {
  double x[4 * N], y[4 * N];
  int lz[4 * N];
  void apply(int i, int ang) {
    (lz[i] += ang) %= 360;
    double nx = x[i] * c[ang] - y[i] * s[ang];
    double ny = y[i] * c[ang] + x[i] * s[ang];
    x[i] = nx;
    y[i] = ny;
  }
  void down(int i) {
    apply(i * 2, lz[i]);
    apply(i * 2 + 1, lz[i]);
    lz[i] = 0;
  }
  void build(int l, int r, int i) {
    x[i] = r - l + 1;
    if (l == r) return;
    build(l, (l + r) / 2, i * 2);
    build((l + r) / 2 + 1, r, i * 2 + 1);
  }
  void update_length(int l, int r, int i, int u, int v) {
    if (l == r) {
      double dis = hypot(x[i], y[i]);
      x[i] *= (dis + v) / dis;
      y[i] *= (dis + v) / dis;
      return;
    }
    down(i);
    if (u <= (l + r) / 2)
      update_length(l, (l + r) / 2, i * 2, u, v);
    else
      update_length((l + r) / 2 + 1, r, i * 2 + 1, u, v);
    x[i] = x[i * 2] + x[i * 2 + 1];
    y[i] = y[i * 2] + y[i * 2 + 1];
  }
  void update_angle(int l, int r, int i, int L, int R, int v) {
    if (l > R || r < L || L > R) return;
    if (L <= l && r <= R) return apply(i, v);
    down(i);
    update_angle(l, (l + r) / 2, i * 2, L, R, v);
    update_angle((l + r) / 2 + 1, r, i * 2 + 1, L, R, v);
    x[i] = x[i * 2] + x[i * 2 + 1];
    y[i] = y[i * 2] + y[i * 2 + 1];
  }
} seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(9);
  for (int i = 0; i < 360; i++) {
    double rad = i / 180.0 * PI;
    s[i] = sin(rad);
    c[i] = cos(rad);
  }
  cin >> n >> q;
  seg.build(1, n, 1);
  while (q--) {
    cin >> t >> u >> v;
    if (t == 1)
      seg.update_length(1, n, 1, u, v);
    else
      seg.update_angle(1, n, 1, u, n, 360 - v);
    cout << seg.x[1] << " " << seg.y[1] << '\n';
  }
}
