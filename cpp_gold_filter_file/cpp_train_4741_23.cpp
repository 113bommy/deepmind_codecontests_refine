#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << 2 * (n / 3) + int(n % 3 != 0) << endl;
}
