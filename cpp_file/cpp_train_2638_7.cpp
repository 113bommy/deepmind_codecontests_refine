#include <bits/stdc++.h>
using namespace std;
const unsigned _mod = 998244353;
const unsigned mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % mod;
    y >>= 1ll;
    x = x * x % mod;
  }
  return ret;
}
long long qpow(long long x, long long y, long long m) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % m;
    y >>= 1ll;
    x = x * x % m;
  }
  return ret;
}
long long _gcd(long long x, long long y) { return y ? _gcd(y, x % y) : x; }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int h, m, n, ans, num, x, vis[200010], b[200010], rk[200010], r, c, j;
string s;
set<int> a[200010];
map<int, pair<int, int> > mp;
int main() {
  cin >> h >> m >> n;
  for (register int i = 0; i <= h - 1; ++i)
    if (!vis[i]) {
      for (int c = 0, j = i; !vis[j]; j = (j + m) % h, c++)
        rk[j] = r, b[j] = c, a[r].insert(c), vis[j] = 1;
      r++;
    }
  for (register int i = 1; i <= n; ++i) {
    cin >> s;
    num = read();
    if (s[0] == '-') a[mp[num].first].insert(mp[num].second);
    if (s[0] == '+') {
      x = read();
      int A = rk[x], B = b[x];
      auto it = a[A].lower_bound(B);
      if (it != a[A].end())
        ans += *it - B;
      else
        it = a[A].begin(), ans += h / r - B + *it;
      mp[num] = make_pair(A, *it);
      a[A].erase(it);
    }
  }
  cout << ans << '\n';
  return 0;
}
