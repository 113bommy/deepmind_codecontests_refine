#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const long double eps = 1e-10;
const int N = 1e5 + 10;
struct Point {
  long double x, y;
  Point(long double x = 0, long double y = 0) : x(x), y(y) {}
  friend Point operator+(Point A, Point B) {
    return Point(A.x + B.x, A.y + B.y);
  }
  friend Point operator-(Point A, Point B) {
    return Point(A.x - B.x, A.y - B.y);
  }
  friend Point operator*(Point A, long double B) {
    return Point(A.x * B, A.y * B);
  }
  friend Point operator/(Point A, long double B) {
    return Point(A.x / B, A.y / B);
  }
  long double len() { return sqrt(x * x + y * y); }
  long double len2() { return x * x + y * y; }
} u, v, m, d;
long double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
int dcmp(long double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
long double In[N], Out[N];
int main() {
  scanf("%Lf%Lf%Lf%Lf", &u.x, &u.y, &v.x, &v.y);
  m = (u + v) / 2;
  Point d1 = d = v - m;
  long double tmp = d1.len();
  d1 = d1 / tmp;
  d.x = d1.y, d.y = -d1.x;
  long double limt = sqrt(1e12 * 1e12 - (v - m).len2());
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    long double r;
    Point o;
    scanf("%Lf%Lf%Lf", &o.x, &o.y, &r);
    int flg = dcmp(Cross(o - u, v - u)) >= 0 ? 1 : -1;
    long double lb = -limt, rb = limt;
    int times = 0;
    while (times++ <= 200 && rb - lb > eps) {
      long double mid = (lb + rb) / 2;
      Point O = m + d * mid;
      long double R = (v - O).len(), oo = (o - O).len();
      if (dcmp(oo - R - r) > 0) {
        if (flg == 1)
          lb = mid;
        else
          rb = mid;
      } else {
        if (flg == 1)
          rb = mid;
        else
          lb = mid;
      }
    }
    long double L = lb;
    lb = -1e12, rb = 1e12;
    times = 0;
    while (times++ <= 200 && rb - lb > eps) {
      long double mid = (lb + rb) / 2;
      Point O = m + d * mid;
      long double R = (v - O).len(), oo = (o - O).len();
      if (dcmp(R - oo - r) > 0) {
        if (flg == 1)
          rb = mid;
        else
          lb = mid;
      } else {
        if (flg == 1)
          lb = mid;
        else
          rb = mid;
      }
    }
    long double R = lb;
    if (L > R) swap(L, R);
    In[i] = L, Out[i] = R;
  }
  sort(In + 1, In + n + 1), sort(Out + 1, Out + n + 1);
  long double ans = 1e12, lst = -1e13;
  int p1 = 1, p2 = 1, cnt = 0;
  while (p1 <= n || p2 <= n) {
    long double cur =
        (p1 <= n && (p2 > n || In[p1] < Out[p2])) ? In[p1] : Out[p2];
    if (cnt == 0) {
      if (lst < 0 && cur > 0) ans = 0;
    }
    while (p2 <= n && dcmp(Out[p2] - cur) == 0) cnt--, p2++;
    if (cnt == 0) ans = min(ans, fabs(cur));
    while (p1 <= n && dcmp(In[p1] - cur) == 0) cnt++, p1++;
    lst = cur;
  }
  ans = min(ans, lst);
  ans = sqrt(ans * ans + (v - m).len2());
  printf("%.10Lf\n", ans);
  return 0;
}
