#include <bits/stdc++.h>
using namespace std;
double low, high = 1e15, mid;
int n, p, a[100001], b[100001];
bool ok(double x) {
  double sum = 0, num;
  for (int i = 0; i < n; i++) {
    num = x * a[i] - b[i];
    if (num >= 0) sum += num / p;
  }
  return sum <= x;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  if (ok(high + 1)) return cout << -1, 0;
  for (int i = 0; i < 1000; i++) {
    mid = (low + high) / 2;
    if (ok(mid))
      low = mid;
    else
      high = mid;
  }
  cout << fixed << setprecision(10) << low;
}
