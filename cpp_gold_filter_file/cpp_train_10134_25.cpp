#include <bits/stdc++.h>
using namespace std;
int a, n, d, t, v;
double ans[100001];
double gets_ans() {
  double t1 = v * 1.0 / a;
  if (0.5 * a * t1 * t1 <= d) return t + t1 + (d - 0.5 * a * t1 * t1) / v;
  return sqrt(2.0 * d / a) + t;
}
int main() {
  cin >> n >> a >> d;
  for (int i = 0; i < n; i++) {
    cin >> t >> v;
    ans[i] = gets_ans();
    if (i != 0 && ans[i] < ans[i - 1]) ans[i] = ans[i - 1];
    printf("%.10lf\n", ans[i]);
  }
}
