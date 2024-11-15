#include <bits/stdc++.h>
using namespace std;
const int nn = 100005;
struct mrx {
  int x1, x2, y1, y2, z, p;
} a[nn];
int n, m, l[nn], r[nn];
void read(int &x) {
  char ch = getchar();
  for (; ch < 48; ch = getchar())
    ;
  for (x = 0; ch >= 48; ch = getchar()) x = x * 10 + ch - 48;
}
inline bool cmp(const mrx &x, const mrx &y) { return x.z < x.z; }
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i].x1);
    read(a[i].x2);
    read(a[i].y1);
    read(a[i].y2);
    read(a[i].z);
    a[i].p = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
  r[0] = 1;
  l[0] = n;
  r[n] = 0;
  read(m);
  for (int i = 1; i <= m; ++i) {
    int x, y, j = 0;
    read(x);
    read(y);
    for (j = r[0]; j; j = r[j])
      if (x >= a[j].x1 && x <= a[j].x2 && y >= a[j].y1 && y <= a[j].y2) {
        r[l[j]] = r[j], l[r[j]] = l[j];
        break;
      }
    printf("%d\n", a[j].p);
  }
  return 0;
}
