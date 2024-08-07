#include <bits/stdc++.h>
using namespace std;
int n, l, r, mid, b[5005], x[5005], y[5005], d[5005][5005];
inline int abs(int a) { return a > 0 ? a : -a; }
bool dfs(int i, int k) {
  if (b[i] >= 0) return b[i] - k;
  b[i] = k;
  for (int j = 1; j <= n; j++)
    if (d[i][j] > mid)
      if (dfs(j, k ^ 1)) return 1;
  return 0;
}
int cal() {
  memset(b, -1, sizeof(b));
  int res = 1;
  for (int i = 1; i <= n; i++)
    if (b[i] < 0) {
      if (dfs(i, 0)) return -1;
      res = res * 2 % 1000000007;
    }
  return res;
}
int main() {
  scanf("%d", &n), l = 0, r = 10000, mid;
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
  while (l < r) {
    mid = (l + r) / 2;
    if (cal() < 0)
      l = mid + 1;
    else
      r = mid;
  }
  mid = l, printf("%d\n%d\n", l, cal());
  return 0;
}
