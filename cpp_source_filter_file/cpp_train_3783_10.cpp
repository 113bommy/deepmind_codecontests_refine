#include <bits/stdc++.h>
using namespace std;
const int N = 555;
int a[N][N];
int sum[N][N];
int n, m;
int ans = 0;
int getSum(int x2, int y2, int x1, int y1) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
void work(int x1, int y1) {
  int x2 = x1 + 2;
  int y2 = y1 + 2;
  if (x2 > n || y2 > m) return;
  int spiral = getSum(x2, y2, x1, y1) - a[x1 + 1][y1] - a[x1 + 1][y1 + 1];
  ans = max(ans, spiral);
  while (true) {
    x1--;
    y1--;
    x2++;
    y2++;
    if (x2 > n || y2 > m || x1 < 1 || y1 < 1) return;
    spiral = getSum(x2, y2, x1, y1) - spiral - a[x1 + 1][y1];
    ans = max(ans, spiral);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) work(i, j);
  printf("%d\n", ans);
  return 0;
}
