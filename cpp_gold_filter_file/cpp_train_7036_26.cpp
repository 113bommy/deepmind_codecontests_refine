#include <bits/stdc++.h>
using namespace std;
int a[333];
int main() {
  int T, n, i, s;
  n = 250;
  cin >> T;
  while (T--) {
    for (i = 1; i <= n; i = i + 1) {
      cin >> a[i];
      s += a[i];
    }
    s /= n;
    sort(a + 1, a + n + 1);
    if (a[220] - a[30] > s)
      cout << "uniform" << endl;
    else
      cout << "poisson" << endl;
  }
  return 0;
}
