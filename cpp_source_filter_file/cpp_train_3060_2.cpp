#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, l, t, a[N << 1];
int main() {
  scanf("%d%d%d", &n, &l, &t);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = n; i < 2 * n; i++) a[i] = l + a[i - n];
  int k = 2 * t / l;
  double ans = 1.0 * n * (n - 1) / 2 * k;
  l = (2 * t) - k * l;
  int r = 0;
  for (int i = 0; i < n; i++) {
    while (r < n * 2 && a[r] - a[i] <= l) r++;
    ans += r - i - 1;
  }
  printf("%.10f\n", ans * 0.25);
  return 0;
}
