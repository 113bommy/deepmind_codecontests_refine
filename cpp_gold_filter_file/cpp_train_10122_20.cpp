#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << '0' << endl;
    } else if (((a > b) && (a - b) % 2 == 1) || ((a < b) && (b - a) % 2 == 0)) {
      cout << '2' << endl;
    } else {
      cout << '1' << endl;
    }
  }
  return 0;
}
