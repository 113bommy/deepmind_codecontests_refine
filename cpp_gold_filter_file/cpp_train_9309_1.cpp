#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    n / l* r >= n ? cout << "Yes\n" : cout << "No\n";
  }
}
