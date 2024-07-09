#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  string res;
  char lst0 = 'a', lst1 = 'a';
  for (int i = 0; i < n; ++i) {
    if (s[i] >= lst0) {
      res += '0';
      lst0 = s[i];
    } else if (s[i] >= lst1) {
      res += '1';
      lst1 = s[i];
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl << res << endl;
  return 0;
}
