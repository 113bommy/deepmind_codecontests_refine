#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, e;
  long long g1, g2, ans;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> e;
    if (i == 0) {
      ans = 0;
      g1 = -e;
      g2 = e;
    } else {
      g1 = max(g1, ans - e);
      g2 = max(g2, ans + e);
      ans = max(g1 + e, g2 - e);
    }
  }
  cout << ans << endl;
  return 0;
}
