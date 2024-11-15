#include <bits/stdc++.h>
using namespace std;
const int md = 1e6 + 3;
int n, c;
int ans;
int cur;
int fact[1000000];
int rfact[1000000];
int bpow(int a, int b) {
  if (b == 0) return 1;
  int res = (bpow(a, b >> 1));
  res = (res * 1ll * res) % md;
  if (b & 1) res = (res * 1ll * a) % md;
  return res;
}
int koef(int n, int k) {
  int a = fact[n];
  int b = (rfact[k] * 1ll * rfact[n - k]) % md;
  return (a * 1ll * b) % md;
}
int main() {
  cin >> n >> c;
  fact[0] = rfact[0] = fact[1] = rfact[1] = 1;
  for (int i = 2; i <= 555555; ++i) {
    fact[i] = (fact[i - 1] * 1ll * i) % md;
    rfact[i] = bpow(fact[i], md - 2);
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + koef(c + i - 1, c - 1)) % md;
    cur = (c * 1ll * cur) % md;
  }
  cout << ans << "\n";
}
