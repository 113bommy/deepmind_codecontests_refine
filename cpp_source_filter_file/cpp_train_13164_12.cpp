#include <bits/stdc++.h>
using namespace std;
double x[3000], y[3000], z[3000], mm = 99999999;
int n, i, j, k;
double d(int u, int v) {
  double p;
  p = sqrt(((x[u] - x[v]) * (x[u] - x[v])) + ((y[u] - y[v]) * (y[u] - y[v])) +
           ((z[u] - z[v]) * (z[u] - z[v])));
  return p;
}
int main() {
  cin >> n;
  for (i = 1; i < n + 1; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  double tt = 0;
  for (i = 2; i < n; i++)
    for (j = i + 1; j < n + 1; j++) {
      tt = d(i, j) + d(1, j) + d(1, i);
      mm = min(mm, tt);
    }
  printf("%.6f", mm / 2);
}
