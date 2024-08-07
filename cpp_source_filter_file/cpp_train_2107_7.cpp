#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * f;
}
const long long N = 1e6 + 10, M = 1e6 + 10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (count(a.begin(), a.end(), a[0]) == n) {
      cout << 1 << endl;
      for (int i = 0; i < n; i++) cout << 1 << " ";
      cout << endl;
      continue;
    }
    if (n % 2 == 0) {
      cout << 2 << endl;
      for (int i = 0; i < n; i++) cout << i % 2 + 1 << " ";
      cout << endl;
      continue;
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[(i + 1) % n]) {
        vector<int> ans(n);
        for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1) ans[pos] = j + 1;
        for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1) ans[pos] = j + 1;
        cout << 2 << endl;
        for (int pos = 0; pos < n; pos++) cout << ans[pos] << " ";
        cout << endl;
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    cout << 3 << endl;
    for (int i = 0; i < n; i++) cout << i % 2 + 1 << " ";
    cout << 3 << endl;
  }
  return 0;
}
