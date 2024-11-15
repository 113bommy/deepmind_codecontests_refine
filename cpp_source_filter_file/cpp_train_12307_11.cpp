#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int n;
double x[2005], y[2005], r[2005];
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
struct Pos {
  double val;
  int id;
  Pos() {}
  Pos(double val, int id) : val(val), id(id) {}
  bool operator<(const Pos &p) const {
    if (fabs(val - p.val) > 1e-8) return val < p.val;
    return id < p.id;
  }
} p[2005 * 2];
int calc(double al) {
  int i, k, cnt, rlt;
  double sa, ca, val;
  sa = sin(al), ca = cos(al);
  for (k = i = 0; i < n; i++) {
    val = -x[i] * sa + y[i] * ca;
    p[k++] = Pos(val - r[i], 1);
    p[k++] = Pos(val + r[i], -1);
  }
  sort(p, p + k);
  rlt = 0;
  for (cnt = i = 0; i < k; i++) {
    cnt += p[i].id;
    chkmax(rlt, cnt);
  }
  return rlt;
}
int main() {
  int TC, i, tmp, val, rlt, m;
  double st, en, stp, al, ang;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
  st = 0, en = 2 * pi;
  rlt = 0;
  for (stp = 0.001; stp > 1e-8; stp /= 10) {
    val = 0;
    for (al = st; al < en; al += stp) {
      tmp = calc(al);
      if (val < tmp) {
        val = tmp;
        ang = al;
      }
    }
    st = ang - stp * 5, en = ang + stp * 5;
    chkmax(rlt, val);
  }
  printf("%I64d\n",
         1LL * (m + 1) * m / 2 + 1LL * (rlt - 1) * (m + 1) + 1 + (n - rlt));
}
