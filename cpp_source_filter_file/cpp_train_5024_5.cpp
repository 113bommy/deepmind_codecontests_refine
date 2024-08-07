#include <bits/stdc++.h>
using namespace std;
int cnt[33], n;
void solve() {
  cin >> n;
  for (int i = 0; i <= 30; i++) cnt[i] = 0;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    for (int j = 0; j <= 30; j++)
      if ((1 << j) & a) cnt[j]++;
  }
  int odd = -1;
  for (int j = 0; j <= 30; j++)
    if (cnt[j] & 1) odd = j;
  if (odd == -1) {
    cout << "DRAW\n";
    return;
  }
  int x = cnt[odd];
  if (x == 1) {
    cout << "WIN\n";
    return;
  }
  if ((n - x) % 2 == 0) {
    cout << "LOSE\n";
    return;
  }
  cout << "WIN\n";
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) solve();
  return 0;
}
