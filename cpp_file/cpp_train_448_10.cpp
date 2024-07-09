#include <bits/stdc++.h>
using namespace std;
int a[100005], d[100005], p[33];
int main() {
  ios_base::sync_with_stdio(0);
  int n, i, j;
  cin >> n;
  p[0] = 1;
  for (i = 1; i < 33; i++) p[i] = p[i - 1] * 2;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 33; j++)
      if (i + p[j] < n && i + p[j + 1] >= n) break;
    a[i + p[j]] += a[i];
    d[i] = a[i];
    if (i) d[i] += d[i - 1];
    a[i] = 0;
  }
  for (i = 0; i < n - 1; i++) cout << d[i] << '\n';
  return 0;
}
