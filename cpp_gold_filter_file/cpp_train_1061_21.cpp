#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = (n + 1) / 3;
  cout << n / 12 << ' ' << n % 12 << endl;
  return 0;
}
