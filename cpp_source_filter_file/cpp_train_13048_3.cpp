#include <bits/stdc++.h>
using namespace std;
int n, d, m, l, k, x, y, p;
int main() {
  cin >> n >> d >> m >> l;
  for (k = 0; k < n; k++) {
    x = k * m, y = x + l;
    if (x <= p && p <= y) p += ((y - p) / d + 1) * d;
  }
  cout << p;
}
