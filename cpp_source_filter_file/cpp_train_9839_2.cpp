#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solveCP311() {
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;
  ll x = 0;
  for (ll i = 2; i <= n; i = i * 2) {
    x = x + i;
  }
  cout << sum - 2 * x << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solveCP311();
  }
  return 0;
}
