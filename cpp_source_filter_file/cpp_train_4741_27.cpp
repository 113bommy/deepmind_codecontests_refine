#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << 2 * a / 3 + (a % 3 != 0 ? 1 : 0);
}
