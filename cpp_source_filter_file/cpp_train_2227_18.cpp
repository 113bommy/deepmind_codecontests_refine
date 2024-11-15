#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, mi1[MAXN], mx1[MAXN], mi2[MAXN], mx2[MAXN];
struct Point {
  int x, y;
} P[MAXN];
bool operator<(const Point &A, const Point &B) { return A.x < B.x; }
int main() {
  scanf("%d", &n);
  int i, j, x, y;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    P[i].x = x + y, P[i].y = x - y;
  }
  sort(P + 1, P + n + 1);
  mi1[1] = mx1[1] = P[1].y;
  for (i = 2; i <= n; i++) {
    mi1[i] = min(mi1[i - 1], P[i].y);
    mx1[i] = max(mx1[i - 1], P[i].y);
  }
  mi2[n] = mx2[n] = P[n].y;
  for (i = n - 1; i >= 1; i--) {
    mi2[i] = min(mi2[i + 1], P[i].y);
    mx2[i] = max(mx2[i + 1], P[i].y);
  }
  mi1[0] = mi2[n + 1] = 2e9;
  mx1[0] = mx2[n + 1] = -2e9;
  double L = 0, R = 2e9, M;
  while (R - L > 1e-7) {
    M = (L + R) / 2;
    bool ok = false;
    for (i = j = 1; i <= n; i++) {
      while (j <= n && P[j].x - P[i].x <= M) j++;
      if (max(mx1[i - 1], mx2[j]) - min(mi1[i - 1], mi2[j]) < M) {
        ok = true;
        break;
      }
    }
    (ok ? R : L) = M;
  }
  printf("%.7f", L);
  return 0;
}
