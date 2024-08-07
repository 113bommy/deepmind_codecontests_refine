#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, l, r;
};
bool f(point a, point b) { return a.r > b.r; }
point a[5000];
int par[5000];
void init(int n) {
  for (int i = 1; i <= n; i++) par[i] = i;
}
int root(int n) {
  if (par[n] == n) return n;
  return par[n] = root(par[n]);
}
int main() {
  int n, m, maxx = 0;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y >> a[i].l >> a[i].r;
  sort(a + 1, a + m + 1, f);
  for (int i = 1; i <= 2; i++) {
    init(n);
    for (int j = 1; j <= 2; j++) {
      if (a[j].l > a[i].l) continue;
      int q1 = root(a[j].x), q2 = root(a[j].y);
      if (q1 != q2) par[q1] = q2;
      if (root(1) == root(n)) maxx = max(maxx, a[j].r - a[i].l + 1);
    }
  }
  if (!maxx)
    cout << "Nice work, Dima!" << endl;
  else
    cout << maxx << endl;
  return 0;
}
