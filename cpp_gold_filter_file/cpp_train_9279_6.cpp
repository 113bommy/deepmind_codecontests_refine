#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, i, c, a;
  cin >> n >> x >> y;
  a = y - n + 1;
  c = a * a + n - 1;
  if (n > y || a < 1 || c < x)
    cout << "-1";
  else {
    cout << a << "\n";
    for (i = 0; i < n - 1; i++) cout << "1\n";
  }
  return 0;
}
