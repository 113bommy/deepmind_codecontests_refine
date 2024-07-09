#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e4 + 10;
int a[maxn], b[maxn];
int main() {
  int n, c;
  cin >> n >> c;
  if (c < n) {
    cout << 0 << endl;
    return 0;
  }
  c -= n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int m = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != 0) {
      a[m] = a[i];
      b[m] = b[i];
      m++;
    }
  if (m == 0) {
    if (c == 0) {
      cout << -1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  long long least = 0;
  for (int i = 0; i < m; i++) {
    least += a[i] / b[i];
  }
  if (least > c) {
    cout << 0 << endl;
    return 0;
  }
  long long lf = 0;
  long long rg = (long long)1e18;
  while (lf < rg - 1) {
    long long mm = (lf + rg) >> 1;
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
      sum += floor(a[i] * 1.0 / b[i] * mm + eps);
      if (sum >= c) break;
    }
    if (sum >= c) {
      rg = mm;
    } else {
      lf = mm;
    }
  }
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    sum += (long long)(a[i] * 1.0 / b[i] * rg + eps);
  }
  if (sum > c) {
    cout << 0 << endl;
    return 0;
  }
  int res = (int)1e9 + 10;
  for (int i = 0; i < m; i++) {
    int ost = a[i] % b[i] * 1LL * (rg % b[i]) % b[i];
    res = min(res, 1 + (b[i] - ost) / a[i] - ((b[i] - ost) % a[i] == 0));
  }
  cout << res << endl;
  return 0;
}
