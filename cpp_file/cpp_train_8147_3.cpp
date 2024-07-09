#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, mini, ans, jmin, v;
int query(int i, int j) {
  int ans;
  cout << "? " << i << ' ' << j << '\n';
  cout.flush();
  cin >> ans;
  return ans;
}
int main() {
  cin >> n >> m;
  mini = 1e9 + 1;
  ans = 1e9 + 1;
  for (j = 1; j <= m; j++) {
    v = query(1, j);
    if (v < mini) {
      mini = v;
      jmin = j;
    }
  }
  ans = mini;
  for (i = 1; i <= n; i++) ans = min(ans, query(i, jmin));
  cout << "! " << ans;
  return 0;
}
