#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, x, y, a, b, t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> x >> y >> a >> b;
    x = abs(x - a);
    y = abs(y - b);
    cout << m * n - 2 * (n - x) * (m - y) +
                max(n - 2 * x, (long long)0) * max(m - 2 * y, (long long)0)
         << endl;
  }
}
