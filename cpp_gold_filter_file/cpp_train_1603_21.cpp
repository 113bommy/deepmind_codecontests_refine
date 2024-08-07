#include <bits/stdc++.h>
using namespace std;
struct dat {
  int n;
  int a, b;
  bool operator<(const dat &x) const {
    if (a == x.a) return b > x.b;
    return a < x.a;
  }
} que[200010];
int keep[200010];
int main() {
  int n, m, a, b, t;
  dat temp;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &que[i].a, &que[i].b);
    que[i].b += que[i].a;
    que[i].n = i;
  }
  sort(que, que + m);
  int i = 0;
  memset(keep, 0, sizeof(keep));
  while (i < m) {
    keep[que[i].n] = 1;
    int k = i, j = i;
    while (que[j].a <= que[i].b && j < m) {
      if (que[k].b < que[j].b) k = j;
      j++;
    }
    if (k == i)
      i = j;
    else
      i = k;
  }
  int count = 0;
  for (int i = 0; i < m; i++)
    if (!keep[i]) count++;
  printf("%d\n", count);
  for (int i = 0; i < m; i++)
    if (!keep[i]) printf("%d ", i + 1);
  return 0;
}
