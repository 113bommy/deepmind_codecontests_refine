#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
double dis[5005][5005];
double ans(double a, double b, double c) { return (b + c - a) / 2. + a; }
int main() {
  int n, i, j;
  double x[maxn], y[maxn], z[maxn], mn = 1e+10, tmp;
  cin >> n;
  for (i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      dis[i][j] =
          sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) +
               (z[j] - z[i]) * (z[j] - z[i]));
  for (i = 1; i < n; i++)
    for (j = i + 1; j < n; j++) {
      tmp = ans(dis[0][i], dis[0][j], dis[i][j]);
      mn = min(mn, tmp);
    }
  printf("%.12lf", mn);
}
