#include <bits/stdc++.h>
int a[100010], b[100010], f[100010];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) scanf("%d", &b[i]);
  for (i = 0; i < n; i++) f[a[i]] = b[i];
  for (i = 1; i <= n; i++) printf("%d ", f[i]);
  puts("");
}
