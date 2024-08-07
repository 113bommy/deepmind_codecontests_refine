#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  string s;
  cin >> s;
  long long xb = 0, xs = 0, xc = 0;
  for (char x : s)
    if (x == 'B')
      xb++;
    else if (x == 'C')
      xc++;
    else if (x == 'S')
      xs++;
  long long nb, ns, nc;
  cin >> nb >> ns >> nc;
  long long pb, ps, pc;
  cin >> pb >> ps >> pc;
  long long pare;
  cin >> pare;
  long long l = 0, r = 1e13, o = 0;
  while (l <= r) {
    long long m = (l + r) >> 1;
    long long trosi = 0;
    trosi += max(0ll, m * xb - nb) * pb;
    trosi += max(0ll, m * xc - nc) * pc;
    trosi += max(0ll, m * xs - ns) * ps;
    if (trosi <= pare) {
      o = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << o << '\n';
}
