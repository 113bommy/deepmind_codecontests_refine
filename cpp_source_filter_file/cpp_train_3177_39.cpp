#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, y, z;
int main() {
  cin >> a >> b >> c >> x >> y >> z;
  a = a - x;
  b = b - y;
  c = c - z;
  if (a >= 0) a /= 2;
  if (b >= 0) b /= 2;
  if (c >= 0) c /= 2;
  if (a + b + c > 0)
    cout << "YES";
  else
    cout << "NO";
}
