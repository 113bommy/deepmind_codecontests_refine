#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, id;
};
bool cmp(const node &a, const node &b) { return a.x < b.x; }
node a[100010];
int from[100010];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].x);
      a[i].id = i;
    }
    if (n == 1 || n == 2) {
      printf("0\n");
      for (int i = 0; i < n; i++) printf("1 ");
      puts("");
      continue;
    }
    sort(a, a + n, cmp);
    int ans1 = (a[n - 1].x + a[n - 2].x - a[0].x - a[1].x);
    int ans2, maxx, minn;
    maxx = a[n - 1].x + a[n - 2].x;
    maxx = max(maxx, a[0].x + a[n - 1].x + m);
    minn = a[0].x + a[1].x + m;
    minn = min(a[1].x + a[2].x, minn);
    ans2 = maxx - minn;
    if (ans1 <= ans2) {
      printf("%d\n", ans1);
      for (int i = 0; i < n; i++) printf("1 ");
      puts("");
    } else {
      printf("%d\n", ans2);
      from[a[0].id] = 2;
      for (int i = 1; i < n; i++) from[a[i].id] = 1;
      printf("%d", from[0]);
      for (int i = 1; i < n; i++) printf(" %d", from[i]);
      puts("");
    }
  }
  return 0;
}
