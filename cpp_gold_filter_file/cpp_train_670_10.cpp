#include <bits/stdc++.h>
using namespace std;
double E[5009][5009], p[5009];
int t[5009];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> t[i];
    p[i] /= 100;
  }
  for (int i = n - 1; i >= 0; i--) {
    double pw = pow(1 - p[i], t[i]), sum = 0;
    for (int j = 1; j <= m; j++) {
      sum *= (1 - p[i]);
      if (j > t[i]) sum -= pw * p[i] * (1 + E[i + 1][j - t[i] - 1]);
      sum += p[i] * (1 + E[i + 1][j - 1]);
      E[i][j] = sum;
      if (j >= t[i]) E[i][j] += pw * (1 + E[i + 1][j - t[i]]);
    }
  }
  printf("%.12f\n", E[0][m]);
  return 0;
}
