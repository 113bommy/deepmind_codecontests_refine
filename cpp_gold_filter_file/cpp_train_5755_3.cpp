#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (auto &it : x) cin >> it;
    for (auto &it : y) cin >> it;
    sort(x.begin(), x.end());
    int j = n - 1;
    vector<int> l(n), r(n);
    for (int i = n - 1; i >= 0; --i) {
      while (x[j] - x[i] > k) --j;
      r[i] = j - i + 1;
      if (i + 1 < n) r[i] = max(r[i], r[i + 1]);
    }
    j = 0;
    for (int i = 0; i < n; ++i) {
      while (x[i] - x[j] > k) ++j;
      l[i] = i - j + 1;
      if (i > 0) l[i] = max(l[i], l[i - 1]);
    }
    int ans = 1;
    for (int i = 0; i < n - 1; ++i) {
      ans = max(ans, l[i] + r[i + 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
