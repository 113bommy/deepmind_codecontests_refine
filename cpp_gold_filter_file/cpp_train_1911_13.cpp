#include <bits/stdc++.h>
const int maxn = 500010;
int n, a[maxn], last[maxn], ST[maxn][22], f[maxn][22], lg2[maxn];
long long ans;
int getmax(int x, int y) {
  if (last[x] <= last[y]) return x;
  return y;
}
int get(int x, int y) {
  if (x < 0) return 0;
  int k = lg2[y - x + 1];
  return getmax(ST[x][k], ST[y + 1 - (1 << k)][k]);
}
int main() {
  scanf("%d", &n);
  lg2[1] = 0;
  for (int i = 2; i <= 500000; i++) lg2[i] = lg2[i / 2] + 1;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[n + i] = a[i];
  for (int i = 0; i < n + n; i++) last[i] = i - a[i], ST[i][0] = i;
  for (int j = 0; j < 19; j++)
    for (int i = 0; i < n + n - (1 << j); i++)
      ST[i][j + 1] = getmax(ST[i][j], ST[i + (1 << j)][j]);
  for (int i = 0; i < n + n; i++) f[i][0] = get(last[i], i);
  for (int j = 0; j < 19; j++)
    for (int i = 0; i < n + n; i++) f[i][j + 1] = f[f[i][j]][j];
  for (int i = n; i < n + n; i++) {
    int x = i;
    ans += 1;
    if (last[i] > i - n + 1) ans++;
    for (int j = 19; j >= 0; j--)
      if (last[f[x][j]] > i - n + 1) x = f[x][j], ans += 1 << j;
  }
  printf("%I64d\n", ans);
  return 0;
}
