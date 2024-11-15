#include <bits/stdc++.h>
using namespace std;
int n, x[5010], y[5010], z[5010];
double Dis(int i, int j) {
  return sqrt(((x[i] - x[j]) * (x[i] - x[j])) +
              ((y[i] - y[j]) * (y[i] - y[j])) +
              ((z[i] - z[j]) * (z[i] - z[j])));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  double ans = 1e9;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      ans = min(ans, (Dis(0, i) + Dis(0, j) + Dis(j, i)) / 2);
    }
  }
  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}
