#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
  }
}
