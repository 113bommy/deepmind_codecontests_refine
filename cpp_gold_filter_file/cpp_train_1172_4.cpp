#include <bits/stdc++.h>
using namespace std;
int ans, sum, g, n, m, t, l[510], w[510], h[510], l1[510], w1[510], c[510];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> w[i] >> h[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> l1[i] >> w1[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    sum = 2000000000;
    for (int j = 0; j < m; j++) {
      if (l1[j] < h[i]) continue;
      t = (l1[j] / h[i]) * w1[j];
      g = (l[i] + w[i]) * 2;
      if (g % t == 0)
        g = int(ceil(g / t));
      else
        g = int(ceil(g / t)) + 1;
      g *= c[j];
      sum = min(sum, g);
    }
    ans += sum;
  }
  cout << ans;
}
