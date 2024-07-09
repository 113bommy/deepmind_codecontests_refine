#include <bits/stdc++.h>
using namespace std;
int n, second, a[200000];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int l = 31 - __builtin_clz(n - i);
    second += a[i];
    a[i + (1 << l)] += a[i];
    printf("%d\n", second);
  }
  return 0;
}
