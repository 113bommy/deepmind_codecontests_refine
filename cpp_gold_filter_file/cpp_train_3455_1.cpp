#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1 && k > 0) {
    cout << 0;
    return 0;
  }
  if (k > 0) {
    if (s[0] != '1') {
      s[0] = '1';
      k--;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i] != '0' && k > 0) {
      s[i] = '0';
      k--;
    }
  }
  cout << s;
  return 0;
}
