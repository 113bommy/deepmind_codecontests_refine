#include <bits/stdc++.h>
using namespace std;
string s[22], t[22];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < m; i++) cin >> t[i];
  int q;
  cin >> q;
  while (q--) {
    int y;
    cin >> y;
    y--;
    cout << s[y % m] << t[y % m] << endl;
  }
  return 0;
}
