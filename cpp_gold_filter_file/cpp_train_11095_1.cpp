#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  cout << "YES\n";
  int a, b, c;
  while (n--) {
    cin >> a >> b >> c >> c;
    cout << (2 * (a & 1) + (b & 1) + 1) << "\n";
  }
}
