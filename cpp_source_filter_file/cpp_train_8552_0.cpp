#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; ++i) cin >> a[i];
  long long int sum = 0, sum1 = 0;
  sort(a, a + (2 * n));
  for (int i = 0; i < n; ++i) {
    if (i < n)
      sum += a[i];
    else
      sum1 += a[i];
  }
  if (sum == sum1) {
    for (int i = 0; i < 2 * n; ++i) cout << a[i] << ' ';
    return;
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
