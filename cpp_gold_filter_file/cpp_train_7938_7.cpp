#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
signed main() {
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << x << " " << y << endl;
  for (long long i = 1; i <= n; i++) {
    if (i != x) cout << i << " " << y << endl;
  }
  long long dir = 0;
  for (long long i = 1; i <= m; i++) {
    if (i != y) {
      if (dir == 0) {
        for (long long j = n; j >= 1; j--) {
          cout << j << " " << i << endl;
        }
        dir = 1;
      } else {
        for (long long j = 1; j <= n; j++) {
          cout << j << " " << i << endl;
        }
        dir = 0;
      }
    }
  }
  return 0;
}
