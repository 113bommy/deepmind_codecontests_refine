#include <bits/stdc++.h>
using namespace std;
int a[101], nr, n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n);
  while (m >= 0) {
    m = m - a[n];
    n--;
    nr++;
  }
  cout << nr;
  return 0;
}
