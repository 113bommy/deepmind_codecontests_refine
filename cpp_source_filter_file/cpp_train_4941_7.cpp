#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, f = 1, ans = 0;
  cin >> n;
  while (f + 3 * f * (f + 1) / 2 <= n) {
    if ((n - f) % 3 == 0) ans++;
    f++;
  }
  cout << ans << endl;
  return 0;
}
