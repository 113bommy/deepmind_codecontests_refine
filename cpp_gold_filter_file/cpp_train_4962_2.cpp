#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, t;
  cin >> n >> a >> b >> c >> t;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (b > c || t == x)
      ans += a;
    else {
      int p = t - x;
      ans += p * c + (a - b * p);
    }
  }
  cout << ans;
}
