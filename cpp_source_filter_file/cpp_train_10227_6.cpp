#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1)) &&
        k * k >= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
