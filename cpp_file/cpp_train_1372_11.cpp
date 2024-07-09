#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
double eps = 1e-12;
long long hcf(long long p, long long q) {
  if (p > q) return hcf(q, p);
  if (!p) return q;
  return hcf(q % p, p);
}
long long lcm(long long p, long long q) { return p * q / hcf(p, q); }
long long power(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans *= a;
    a *= a;
    n /= 2;
    a %= mod;
    ans %= mod;
  }
  return ans;
}
long long fac(long long k, long long mod) {
  long long ans = 1;
  for (long long i = 1; i < k + 1; i++) {
    ans *= i;
    ans %= mod;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long q;
  cin >> q;
  vector<long long> l(n, 0), a1;
  for (long long i = 0; i < q; i++) {
    long long k;
    cin >> k;
    if (k == 1) {
      long long x, y;
      cin >> x >> y;
      x--;
      a[x] = y;
      l[x] = i;
      a1.push_back(0);
    } else {
      long long x;
      cin >> x;
      a1.push_back(x);
    }
  }
  for (long long i = q - 2; i >= 0; i--) {
    a1[i] = max(a1[i], a1[i + 1]);
  }
  for (long long i = 0; i < n; i++) {
    cout << max(a[i], a1[l[i]]) << " ";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
