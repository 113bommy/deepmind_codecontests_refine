#include <bits/stdc++.h>
using namespace std;
int m, n;
struct NS {
  int x, y, dy;
} z[1005];
struct WE {
  int x, y, dx;
} h[1005];
bool xj(NS a, WE b) {
  if (b.x < a.x && a.x < (b.x + b.dx) && a.y < b.y && b.y < (a.y + a.dy))
    return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &z[i].x, &z[i].y, &z[i].dy);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &h[i].x, &h[i].y, &h[i].dx);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (xj(z[i], h[j])) {
        int x1, x2, l1, l2, y1, y2;
        x1 = z[i].x;
        x2 = h[j].x;
        l1 = z[i].dy;
        y1 = z[i].y;
        y2 = h[j].y;
        l2 = h[j].dx;
        int anss = min(y2 - y1, y1 + l1 - y2);
        anss = min(anss, x1 - x2);
        anss = min(anss, x2 + l2 - x1);
        ans = max(anss, ans);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
