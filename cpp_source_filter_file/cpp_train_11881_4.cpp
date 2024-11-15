#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
inline int dcmp(double x) { return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
const int maxn = 510;
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) : x(a), y(b) {}
  void Read() { scanf("%lf%lf", &x, &y); }
  Point operator+(const Point &rh) const { return Point(x + rh.x, y + rh.y); }
  Point operator-(const Point &rh) const { return Point(x - rh.x, y - rh.y); }
  Point operator*(const double &k) const { return Point(x * k, y * k); }
  Point operator/(const double &k) const { return Point(x / k, y / k); }
} P[maxn][4];
inline double Cross(const Point &A, const Point &B) {
  return A.x * B.y - A.y * B.x;
}
inline double Dot(const Point &A, const Point &B) {
  return A.x * B.x + A.y * B.y;
}
struct Seg {
  Point a, b;
  Seg() {}
  Seg(Point _a, Point _b) : a(_a), b(_b) {}
};
inline bool LineInsertSeg(const Seg &l1, const Seg &l2) {
  double c1 = Cross(l1.b - l1.a, l2.a - l1.a);
  double c2 = Cross(l1.b - l1.a, l2.b - l1.b);
  return dcmp(c1) * dcmp(c2) < 0;
}
inline Point InsertPoint(const Seg &l1, const Seg &l2) {
  double c1 = Cross(l1.b - l1.a, l2.a - l1.a);
  double c2 = Cross(l1.b - l1.a, l2.b - l1.b);
  return (l2.a * c2 - l2.b * c1) / (c2 - c1);
}
int n;
struct Event {
  Point p;
  double val;
  int sign;
  Event() {}
  Event(Point a, double b, int c) : p(a), val(b), sign(c) {}
  inline bool operator<(const Event &rh) const { return val < rh.val; }
} E[maxn << 1];
inline double Calc(const Point &A, const Point &B, int id) {
  int cnt = 0;
  E[++cnt] = Event(A, Dot(B - A, A - A), 0);
  E[++cnt] = Event(B, Dot(B - A, B - A), 0);
  for (int i = 1; i <= n; i++) {
    Point L = B, R = A;
    double DL = Dot(B - A, L - A), DR = Dot(B - A, R - A);
    for (int j = 0; j < 4; j++) {
      Point C = P[i][j], D = P[i][(j + 1) & 3];
      if (LineInsertSeg(Seg(A, B), Seg(C, D))) {
        Point O = InsertPoint(Seg(A, B), Seg(C, D));
        double Len = Dot(B - A, O - A);
        if (Len < DL) DL = Len, L = O;
        if (Len > DR) DR = Len, R = O;
      } else if (dcmp(Cross(B - A, C - A)) == 0 &&
                 dcmp(Cross(B - A, D - A)) == 0 && id < i) {
        double LenL = Dot(B - A, C - A);
        double LenR = Dot(B - A, D - A);
        if (LenL > LenR) continue;
        if (LenL < DL) DL = LenL, L = C;
        if (LenR > DR) DR = LenR, R = D;
      }
    }
    double PL = Dot(B - A, A - A), PR = Dot(B - A, B - A);
    if (DL < PL) DL = PL, L = A;
    if (DR > PR) DR = PR, R = B;
    if (DL < DR) {
      E[++cnt] = Event(L, DL, 1);
      E[++cnt] = Event(R, DR, -1);
    }
  }
  double Ans = 0;
  int on = 0;
  sort(E + 1, E + 1 + cnt);
  for (int i = 1; i < cnt; i++) {
    on += E[i].sign;
    if (on == 0) Ans += Cross(E[i].p, E[i + 1].p);
  }
  return Ans;
}
void Solve() {
  double UnionArea = 0;
  double AllArea = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 4; j++) {
      UnionArea += Calc(P[i][j], P[i][(j + 1) & 3], i);
      AllArea += Cross(P[i][j], P[i][(j + 1) & 3]);
    }
  double Ans = AllArea / UnionArea;
  printf("%.5lf\n", Ans);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    static Point Ptmp[4];
    for (int j = 0; j < 4; j++) Ptmp[j].Read();
    double S = 0;
    for (int j = 0; j < 4; j++) S += Cross(Ptmp[j], Ptmp[(j + 1) & 3]);
    if (S > 0)
      for (int j = 0; j < 4; j++) P[i][j] = Ptmp[j];
    else
      for (int j = 0; j < 4; j++) P[i][j] = Ptmp[3 - j];
  }
  Solve();
  return 0;
}
