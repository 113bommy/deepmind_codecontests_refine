#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, f, t, s = -1e9;
  cin >> n >> k;
  while (n--) {
    cin >> f >> t;
    if (t <= k)
      s = max(s, f);
    else
      s = max(s, f - t + k);
  }
  cout << s << endl;
  return 0;
}
