#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  int a = 1, t, k;
  cin >> t;
  for (int i = 1; i < n; ++i) {
    cin >> k;
    if (k - t > c) a = 0;
    ++a;
    t = k;
  }
  cout << a << '\n';
}
