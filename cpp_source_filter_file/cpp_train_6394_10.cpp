#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, w;
long long calc(long long s, long long e) {
  long long m = (s + e) / 2;
  if (e - s <= 1) return e;
  long long int k = (m * x - b + w - 1) / w;
  cerr << k << endl;
  if (c - m > a - k) return calc(m, e);
  return calc(s, m);
}
int main() {
  cin >> a >> b >> w >> x >> c;
  if (c <= a) {
    cout << 0 << endl;
    return 0;
  }
  cout << calc(0, 2000000100LL) << endl;
}
