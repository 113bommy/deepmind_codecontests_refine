#include <bits/stdc++.h>
using namespace std;
int l[6];
int main() {
  int n, m, a;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int i = 1; i <= n; i++) {
      cin >> a;
      l[a] = max(l[i - 1], l[i]) + a;
    }
    cout << l[n] << endl;
  }
  return 0;
}
