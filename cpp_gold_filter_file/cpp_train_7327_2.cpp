#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int MOD = 1000000007;
vector<int> vt;
int a[N];
int main() {
  a[0] = 1;
  for (int i = 1; i < N; ++i) {
    a[i] = (a[i - 1] + a[i - 1]) % MOD;
  }
  int n, m, k;
  while (cin >> n >> m >> k) {
    vt.clear();
    bool flag = true;
    while (m--) {
      int l, r;
      cin >> l >> r;
      if (r - l != 1 && r - l != k + 1) {
        flag = false;
      }
      if (r - l == k + 1) {
        vt.push_back(r);
      }
    }
    if (flag == false) {
      cout << "0" << endl;
      continue;
    }
    ++k;
    if (vt.size() >= 2) {
      if (vt[vt.size() - 1] - vt[0] >= k) {
        cout << "0" << endl;
        continue;
      }
    }
    if (k >= n) {
      cout << "1" << endl;
      continue;
    }
    int m = vt.size();
    if (m == 0) {
      int ans = 0;
      ans = a[min(n - k, k)];
      for (int i = k * 2 + 1; i <= n; ++i) {
        ans = (ans + a[k - 1]) % MOD;
      }
      cout << ans << endl;
    } else {
      int ans = 0;
      ans = a[min(n - k, k) - m];
      for (int i = max(vt[m - 1], 2 * k) + 1; i <= n && i - vt[0] < k; ++i) {
        ans = (ans + a[k - 1 - m]) % MOD;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
