#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((a + c - 1) / c >= (b + d - 1) / d ? "Yes" : "No") << endl;
}
