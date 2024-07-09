#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k, l, d[101];
void solve() {
  cin >> n >> k >> l;
  int f = 1;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    d[i] = l - d[i];
  }
  int support = INT_MAX, phase = 0;
  for (int i = 1, j; i <= n; i++) {
    if (d[i] >= k) {
      support = INT_MAX;
      continue;
    }
    if (phase == 0) support = min(support - 1, d[i]);
    if (support < 0) {
      f = 0;
      break;
    }
    if (support == 0) {
      for (j = i; j <= i + k && j <= n; j++) {
        if (d[j] < j - i) {
          f = 0;
          break;
        }
        if (d[j] >= k) {
          support = INT_MAX;
          break;
        }
      }
      if (f == 0) break;
      i = j - 1;
    }
  }
  if (f)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    solve();
  }
  return 0;
}
