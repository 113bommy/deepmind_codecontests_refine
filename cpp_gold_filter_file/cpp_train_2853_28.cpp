#include <bits/stdc++.h>
using namespace std;
int a[12000], id[12000], i, j, k, l, n, m, x;
vector<pair<int, int> > ans;
void spa(int &x, int &y, int &z, int &xx, int &yy, int &zz) {
  if (x > y) swap(x, y), swap(xx, yy);
  if (x > z) swap(x, z), swap(xx, zz);
  if (y > z) swap(y, z), swap(yy, zz);
}
void work(int i) {
  int x = a[i], y = a[i + 1], z = a[i + 2], xx = id[i], yy = id[i + 1],
      zz = id[i + 2], p;
  spa(x, y, z, xx, yy, zz);
  while (x) {
    p = y / x;
    while (p) {
      if (p & 1)
        y -= x, x += x, ans.push_back(make_pair(xx, yy));
      else
        z -= x, x += x, ans.push_back(make_pair(xx, zz));
      p /= 2;
    }
    spa(x, y, z, xx, yy, zz);
  }
  a[i] = x;
  a[i + 1] = y;
  a[i + 2] = z;
  id[i] = xx;
  id[i + 1] = yy;
  id[i + 2] = zz;
}
int main() {
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d", &x);
    if (x) a[++n] = x, id[n] = i;
  }
  if (n < 2) return puts("-1"), 0;
  for (i = 1; i <= n - 2; ++i) work(i);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
