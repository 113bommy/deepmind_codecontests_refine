#include <bits/stdc++.h>
using namespace std;
const int N = 105000;
int n;
int a[N], b[N];
int x[N], y[N];
bool l = 0, r = 0, z = 0;
int mid;
int main() {
  int i;
  scanf("%d", &n);
  mid = (n + 1) >> 1;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    a[i] = x[i];
    b[i] = y[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; i++) {
    if (x[i] <= a[mid]) {
      if (y[i] <= b[mid])
        l = 1;
      else
        r = 1;
    }
    if (x[i] == a[mid] && y[i] == b[mid]) z = 1;
  }
  long long ans = 0;
  for (i = 1; i <= mid; i++) ans -= a[i] + b[i];
  for (i = n; i > n - mid; i--) ans += a[i] + b[i];
  if (n & 1) {
    if (z && l && r) {
      int s = min(a[mid + 1] - a[mid], a[mid] - a[mid - 1]);
      int t = min(b[mid + 1] - b[mid], b[mid] - b[mid - 1]);
      ans -= min(s, t);
      ans <<= 1;
    } else
      ans <<= 1;
  } else {
    if (l && r) {
      ans -= min(a[mid + 1] - a[mid], b[mid + 1] - b[mid]);
      ans <<= 1;
    } else
      ans <<= 1;
  }
  cout << ans << endl;
  return 0;
}
