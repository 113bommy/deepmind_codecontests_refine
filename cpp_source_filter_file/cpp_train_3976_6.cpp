#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
const int oo = 1e9 + 9;
const long long inf = 1e18 + 18;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s, t, e;
    cin >> s >> t >> e;
    cout << max(0, e - max((s + e - t + 2) / 2, 0) + 1) << endl;
  }
}
