#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 9 == 0)
      cout << n / 10 + 1 << endl;
    else
      cout << n / 10 << endl;
  }
  return 0;
}
