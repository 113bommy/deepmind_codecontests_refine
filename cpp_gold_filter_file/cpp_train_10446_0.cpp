#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  cout << (x + x % 2) * (y + y % 2) * (x / 2) / 2 * (y / 2) / 2;
}
