#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, x, y, z, a[5];
  cin >> a[0] >> a[1] >> a[2] >> k;
  k += 3;
  sort(a, a + 3);
  x = min(a[0], k / 3);
  k -= x;
  y = min(a[1], k / 2);
  k -= y;
  z = min(a[2], k);
  cout << x * y * z << endl;
}
