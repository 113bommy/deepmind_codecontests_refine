#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = min(a, b);
    c = min(c, d);
    if (a + c <= n) {
      cout << i + 1 << " " << a << " " << n - a << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
