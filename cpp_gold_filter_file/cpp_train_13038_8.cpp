#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long double a, b;
    cin >> a >> b;
    long double p;
    p = (a * b) / 2;
    cout << int(ceil(p)) << "\n";
  }
  return 0;
}
