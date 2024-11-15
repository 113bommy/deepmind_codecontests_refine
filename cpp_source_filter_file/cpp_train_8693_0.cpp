#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r;
  int c;
  double cnt, lf, rf;
} segTree[100005 * 3];
struct Line {
  double x, y1, y2;
  int f;
} line[100005];
bool cmp(Line a, Line b) { return a.x < b.x; }
double y[100005];
void Build(int t, int l, int r) {
  segTree[t].l = l;
  segTree[t].r = r;
  segTree[t].cnt = segTree[t].c = 0;
  segTree[t].lf = y[l];
  segTree[t].rf = y[r];
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  Build(t << 1, l, mid);
  Build(t << 1 | 1, mid, r);
}
void calen(int t) {
  if (segTree[t].c > 0) {
    segTree[t].cnt = segTree[t].rf - segTree[t].lf;
    return;
  }
  if (segTree[t].l + 1 == segTree[t].r)
    segTree[t].cnt = 0;
  else
    segTree[t].cnt = segTree[t << 1].cnt + segTree[t << 1 | 1].cnt;
}
void update(int t, Line e) {
  if (e.y1 == segTree[t].lf && e.y2 == segTree[t].rf) {
    segTree[t].c += e.f;
    calen(t);
    return;
  }
  if (e.y2 <= segTree[t << 1].rf)
    update(t << 1, e);
  else if (e.y1 >= segTree[t << 1 | 1].lf)
    update(t << 1 | 1, e);
  else {
    Line tmp = e;
    tmp.y2 = segTree[t << 1].rf;
    update(t << 1, tmp);
    tmp = e;
    tmp.y1 = segTree[t << 1 | 1].lf;
    update(t << 1 | 1, tmp);
  }
  calen(t);
}
int main() {
  int i, n, t, iCase = 0;
  double x1, y1, x2, y2, a, b, c, d;
  while (scanf("%d", &n) != EOF) {
    iCase++;
    t = 1;
    for (i = 1; i <= n; i++) {
      scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
      if (a == c) {
        x1 = a;
        x1 -= 1;
        x2 = c;
        if (b > d) swap(b, d);
        y1 = b;
        y2 = d;
        y2 += 1;
      }
      if (b == d) {
        y1 = b;
        y2 = d;
        if (a > c) swap(a, c);
        x1 = a;
        x2 = c;
        y1 -= 1;
        x2 += 1;
      }
      line[t].x = x1;
      line[t].y1 = y1;
      line[t].y2 = y2;
      line[t].f = 1;
      y[t] = y1;
      t++;
      line[t].x = x2;
      line[t].y1 = y1;
      line[t].y2 = y2;
      line[t].f = -1;
      y[t] = y2;
      t++;
    }
    sort(line + 1, line + t, cmp);
    sort(y + 1, y + t);
    Build(1, 1, t - 1);
    update(1, line[1]);
    double res = 0;
    for (i = 2; i < t; i++) {
      res += segTree[1].cnt * (line[i].x - line[i - 1].x);
      update(1, line[i]);
    }
    printf("%.0f", res);
  }
  return 0;
}
