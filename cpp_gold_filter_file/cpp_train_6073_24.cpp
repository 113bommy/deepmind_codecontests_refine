#include <bits/stdc++.h>
int n = 3000000, len = 0, k;
int f[3000005], p[300005], a[15];
bool check(int x) {
  int y = x, l = 0;
  while (y) a[++l] = y % 10, y /= 10;
  for (int i = 1; i <= l; i++) y = y * 10 + a[i];
  return f[y] == y && x != y;
}
int main() {
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 2; i <= n; i++) {
    if (f[i] == i) p[++len] = i;
    for (int j = 1; j <= len && p[j] <= f[i] && p[j] <= n / i; j++)
      f[p[j] * i] = p[j];
  }
  scanf("%d", &k);
  for (int i = 1; i <= len; i++) {
    if (check(p[i])) k--;
    if (!k) {
      printf("%d\n", p[i]);
      return 0;
    }
  }
}
