#include <bits/stdc++.h>
using namespace std;
int n, m, p[1010];
int ans[1010], cnt;
struct E {
  int x, y, l, no;
} e[100010];
inline bool cmp(const E &x, const E &y) { return x.l < y.l; }
inline int find(int x) {
  if (x != p[x]) p[x] = find(p[x]);
  return p[x];
}
int main() {
  scanf("%d%d", &n, &m);
  if (~n & 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    char str[3];
    scanf("%d%d%s", &e[i].x, &e[i].y, &str);
    e[i].l = (str[0] == 'S') ? 1 : 0;
    e[i].no = i;
  }
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = m; i >= 1; i--)
    if (find(e[i].x) != find(e[i].y)) {
      p[find(e[i].x)] = find(e[i].y);
      if (!e[i].l) e[i].l = -1;
    }
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= n; i++) p[i] = i;
  int S = 0, M = 0;
  for (int i = 1; i <= m; i++)
    if ((e[i].l > 0 || S < (n - 1) / 2) && find(e[i].x) != find(e[i].y)) {
      p[find(e[i].x)] = find(e[i].y);
      ans[++cnt] = e[i].no;
      if (e[i].l > 0)
        S++;
      else
        M++;
    }
  if (S < (n - 1) / 2 || M < (n - 1) / 2)
    printf("-1\n");
  else {
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
