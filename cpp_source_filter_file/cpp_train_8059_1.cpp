#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int pr[100007][17];
int inc[100007];
string a;
void input();
void solve();
int main() {
  input();
  solve();
  return 0;
}
void input() {
  cin >> n >> q >> k;
  cin >> a;
}
void solve() {
  int i, j;
  for (i = 1; i <= n; i++) {
    if (a[i - 1] == '1')
      inc[i] = inc[i - 1] + 1;
    else
      inc[i] = inc[i - 1];
  }
  for (j = 1; j <= k; j++) {
    for (i = j; i <= n; i += j) {
      if (a[i - 1] == '1')
        pr[i][j % k] = pr[i - j][j % k] + 1;
      else
        pr[i][j % k] = pr[i - j][j % k];
    }
  }
  int l, r;
  int br1 = 0;
  int br2 = 0;
  int nd;
  while (q != 0) {
    q--;
    cin >> l >> r;
    br1 = inc[r] - inc[l - 1];
    br2 = pr[r][r % k] - pr[l - 1][r % k];
    nd = r - l + 1;
    nd /= k;
    cout << nd - br2 + br1 - br2 << "\n";
  }
}
