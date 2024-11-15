#include <bits/stdc++.h>
using namespace std;
int n, k;
struct point {
  int x, y;
} p[200010];
set<point> ans;
inline bool operator<(const point &a, const point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
inline bool operator==(const point &a, const point &b) {
  return a.x == b.x && a.y == b.y;
}
int main() {
  scanf("%d%d", &n, &k);
  if (k >= n) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < n; i++)
    scanf("%d%d", &p[i].x, &p[i].y), p[i].x *= 2, p[i].y *= 2;
  sort(p, p + n);
  for (int i = 0; i <= k; i++)
    for (int j = n - 1; n - j - 1 - i <= k; j--) {
      if (i > j) break;
      point mid, sym;
      mid.x = p[i].x + p[j].x;
      mid.y = p[i].y + p[j].y;
      int l = i + 1, r = j - 1, cnt = k - i - (n - 1 - j);
      while (l <= r) {
        sym.x = mid.x - p[l].x;
        sym.y = mid.y - p[l].y;
        if (sym == p[r])
          l++, r--;
        else {
          cnt--;
          if (p[r] < sym)
            l++;
          else
            r--;
        }
        if (cnt < 0) break;
      }
      if (cnt >= 0) ans.insert(mid);
    }
  printf("%d\n", (int)ans.size());
  for (set<point>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    printf("%.1lf %.1lf\n", iter->x / 4.0, iter->y / 4.0);
}
