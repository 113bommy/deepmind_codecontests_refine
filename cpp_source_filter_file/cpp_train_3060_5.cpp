#include <bits/stdc++.h>
using namespace std;
int n, l, t;
const int N = 1000006;
int a[N * 2];
int main() {
  cin >> n >> l >> t;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = n; i < n * 2; i++) a[i] = l + a[i - n];
  int len = n + n;
  int k = 2 * t / l;
  int L = 2 * t - k * l;
  double ans = 0.5 * n * n * k;
  int rp = 0;
  for (int i = 0; i < n; i++) {
    while (rp < len && a[rp] - a[i] <= L) rp++;
    ans += (rp - i - 1) * 0.25;
  }
  printf("%.10lf\n", ans);
}
