#include <bits/stdc++.h>
using namespace std;
int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const int maxn = 2e5 + 10;
const int inf = 1e9 + 10;
int mini[maxn];
int mark[maxn];
int res;
int32_t main() {
  int n = in(), m = in(), k = in();
  for (int i = 0; i < n; i++) {
    int row = in();
    if (!mark[row])
      mini[row] = in(), mark[row] = true;
    else
      mark[row] = min(mark[row], in());
  }
  for (int i = 1; i <= m; i++) res += min(mini[i], k), k = max(0, k - mini[i]);
  cout << res << endl;
}
