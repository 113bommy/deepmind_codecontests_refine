#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x, y, t, i, n, m, a[100001];
  cin >> n >> m;
  s = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    cin >> t >> x;
    if (t == 1) {
      cin >> y;
      a[x - 1] = y;
    }
    if (t == 2) s += x;
    if (t == 3) cout << a[x - 1] + s << endl;
  }
}
