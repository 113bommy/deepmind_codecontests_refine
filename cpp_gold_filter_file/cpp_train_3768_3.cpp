#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0, c;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c, s += c;
    s = ceil(s * 1.0 / n * 1.0);
    cout << s << '\n';
  }
}
