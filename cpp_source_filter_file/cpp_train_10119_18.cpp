#include <bits/stdc++.h>
using namespace std;
int p[8], n, k, ans = 1 << 28;
string d[9];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 0; i < 7; i++) p[i] = i + 1;
  do {
    int mn = 1 << 28, mx = 0;
    for (int i = 1; i <= n; i++) {
      int num = 0;
      for (int j = 0; j < k; j++) num = num * 10 + d[i][p[j] - 1] - '0';
      mn = min(mn, num);
      mx = max(mx, num);
    }
    ans = min(ans, mx - mn);
  } while (next_permutation(p, p + k));
  cout << ans;
  return 0;
}
