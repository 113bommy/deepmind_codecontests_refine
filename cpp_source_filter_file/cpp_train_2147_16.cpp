#include <bits/stdc++.h>
using namespace std;
int n, p, s, ans, k[3], t[3], a[3][100010];
int main() {
  for (int i = 0; i < 3; ++i) cin >> k[i];
  for (int i = 0; i < 3; ++i) cin >> t[i];
  ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    s = p;
    for (int j = 0; j < 3; ++j)
      s = a[j][i % k[j]] = max(a[j][i % k[j]], s) + t[j];
    ans = max(ans, s - p);
  }
  cout << ans << endl;
  return 0;
}
