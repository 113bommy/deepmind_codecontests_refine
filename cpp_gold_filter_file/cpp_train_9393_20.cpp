#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
    } else {
      cout << "4";
      for (int i = 1; i < n; ++i) {
        cout << "7";
      }
      cout << "\n";
    }
  }
  return 0;
}
