#include <bits/stdc++.h>
using namespace std;
int a, s, d, f, g, h, j, k, l, i, n, m;
int main() {
  cin >> n >> m;
  k = n % m;
  if (k != 0) l = 1;
  for (i = 0; i < m; i++) {
    if (k != 0) {
      cout << n / m << " ";
      k--;
    } else
      cout << n / m + l << " ";
  }
}
