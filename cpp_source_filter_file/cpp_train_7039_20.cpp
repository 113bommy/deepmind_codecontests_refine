#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1024 * 1024;
int l, m, mx = 1, p;
int main() {
  cin >> l >> m;
  while (mx <= m) mx *= 10;
  p = mx / 2;
  p = (p > l) ? (p) : (l);
  p = (p > m) ? (m) : (p);
  cout << p * (mx - 1 - p) << endl;
  return 0;
}
