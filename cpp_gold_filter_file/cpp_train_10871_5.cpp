#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 6;
const int mod = 1000 * 1000 * 1000 + 7;
int n;
int a[maxN];
bool check(int st, int t) {
  int ld = 0, rd = 1000 * 100;
  for (int i = 1; i < n; i++) {
    int mxd = (a[i] + t - st) / i;
    int mid = (a[i] - t + i - 1 - st) / i;
    ld = max(ld, mid);
    rd = min(rd, mxd);
  }
  if (ld <= rd) return true;
  return false;
}
int print(int st, int t) {
  int ld = 0, rd = 1000 * 100;
  for (int i = 1; i < n; i++) {
    int mxd = (a[i] + t - st) / i;
    int mid = (a[i] - t + i - 1 - st) / i;
    ld = max(ld, mid);
    rd = min(rd, mxd);
  }
  return ld;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = mod;
  sort(a, a + n);
  int ind = 0;
  for (int i = -20000; i <= 3000; i++) {
    int lo = abs(a[0] - i) - 1, hi = 5 * 10000;
    while (hi - lo > 1) {
      int mid = (hi + lo) >> 1;
      if (check(i, mid))
        hi = mid;
      else
        lo = mid;
    }
    if (ans > hi) {
      ans = hi;
      ind = i;
    }
  }
  cout << ans << endl;
  cout << ind << ' ' << print(ind, ans) << endl;
  return 0;
}
