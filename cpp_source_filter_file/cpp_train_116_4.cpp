#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int pos = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      pos = i;
      break;
    }
  }
  if (pos != -1) {
    cout << "YES" << endl;
    cout << pos << ' ' << pos + 1 << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
