#include <bits/stdc++.h>
using namespace std;
struct de {
  int x, y;
} s[25010];
bool cmp(de a, de b) { return a.x + a.y < b.x + b.y; }
int main() {
  int w = 0;
  int n, m, k, i, j;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      s[w].x = i;
      s[w].y = j;
      w++;
    }
  sort(s, s + w, cmp);
  int ans = 0;
  for (i = k - 1; i >= 0; i--) {
    ans = ans + s[i].x - 1 + s[i].y;
  }
  printf("%d\n", ans);
  for (i = k - 1; i >= 0; i--) {
    for (j = 1; j < s[i].y; j++) printf("(1,%d) ", j);
    for (j = 1; j <= s[i].x; j++) printf("(%d,%d) ", j, s[i].y);
    printf("\n");
  }
}
