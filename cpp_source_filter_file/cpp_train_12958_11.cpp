#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
};
vector<pt> a;
bool cmp(pt a, pt b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
void convex_hull(vector<pt>& a) {
  if (a.size() == 1) return;
  sort(a.begin(), a.end(), &cmp);
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < a.size(); ++i) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (size_t i = 0; i < up.size(); ++i) a.push_back(up[i]);
  for (size_t i = down.size() - 2; i > 0; --i) a.push_back(down[i]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pt O;
    O.x = x - 1;
    O.y = y;
    a.push_back(O);
    O.x = x + 1;
    O.y = y;
    a.push_back(O);
    O.x = x;
    O.y = y + 1;
    a.push_back(O);
    O.x = x;
    O.y = y - 1;
    a.push_back(O);
  }
  convex_hull(a);
  long long ans = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    int x = abs(a[i + 1].x - a[i].x);
    int y = abs(a[i + 1].y - a[i].y);
    ans += max(x, y);
  }
  int x = abs(a[0].x - a[a.size() - 1].x);
  int y = abs(a[0].y - a[a.size() - 1].y);
  ans += max(x, y);
  printf("%I64d\n", ans);
  return 0;
}
