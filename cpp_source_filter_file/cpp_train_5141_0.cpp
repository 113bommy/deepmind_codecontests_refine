#include <bits/stdc++.h>
using namespace std;
int n, a[32], v[1 << 23];
int bits(int x) { return x ? (1 + bits(x - (x & -x))) : 0; }
int go(int b, int u) {
  int& r = v[b];
  if (r < 1) {
    r = 99;
    if (u > 1) {
      for (int i = u; i-- > 0;)
        for (int j = i + 1; j-- > 0;)
          if (a[i] + a[j] == a[u])
            r = min(r, go((b ^ (1 << u)) | (1 << (u - 1)) | (1 << i) | (1 << j),
                          u - 1));
      r = max(r, bits(b));
    } else
      r = 1;
  }
  return r;
}
int main(void) {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int r = go(1 << (n - 1), n - 1);
  cout << (r < 98 ? r : -1) << endl;
}
