#include <bits/stdc++.h>
using namespace std;
string s, t;
int q;
int main() {
  cin >> s;
  t = s;
  cin >> q;
  for (int l, r, k, L, i = 0; i < q; i++) {
    cin >> l >> r >> k;
    l--, r--;
    L = r - l + 1;
    for (int i = 0; i < L; i++) t[i + l] = s[l + ((i - k + L) % L)];
    s = t;
  }
  cout << s << endl;
  return 0;
}
