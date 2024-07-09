#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
template <class T>
T sqr(T a) {
  return a * a;
}
int n, k;
long long l, r;
long long d[1 << 20];
string st[50];
int bit[1 << 25];
void init() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> st[i];
  k = st[0].size();
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int mask = 0;
      for (int r = 0; r < k; ++r)
        if (st[i][r] == st[j][r]) mask |= 1ll << r;
      d[mask] |= 1ll << i;
      d[mask] |= 1ll << j;
    }
}
void precalc() {
  for (int i = 1; i < (1 << 25); ++i) {
    int k = 0, mask = i;
    while (mask) {
      k += mask & 1;
      mask >>= 1;
    }
    bit[i] = k;
  }
}
double ver[1 << 20];
void solve() {
  precalc();
  for (int i = (1 << k) - 1; i > 0; --i) {
    for (int j = 0; j < k; ++j) {
      if ((1 << j) & i) d[(1 << j) ^ i] |= d[i];
    }
  }
  ver[0] = 1;
  double ans = 0;
  for (int i = 0; i < (1 << k); ++i) {
    int t = bit[i];
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) continue;
      ver[i ^ (1 << j)] += ver[i] / (k - t);
    }
  }
  for (int i = 0; i < (1 << k) - 1; ++i) {
    int t = bit[i];
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) continue;
      int s = 0;
      long long tmask = d[i] ^ d[i | (1 << j)];
      int mod = (1 << 25) - 1;
      while (tmask) {
        s += bit[tmask & mod];
        tmask >>= 25;
      }
      ans += s / (double)n * (t + 1) * ver[i] / (k - t);
    }
  }
  cout.precision(11);
  cout << fixed << ans;
}
int main() {
  int t;
  init();
  solve();
  return 0;
}
