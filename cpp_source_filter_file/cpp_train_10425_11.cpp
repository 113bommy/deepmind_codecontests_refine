#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if ((n == x / 2 || n == x / 2 + 1) && (n == y / 2 || n == y / 2 + 1))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
