#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 4;
long long add(long long a, long long b, long long m) {
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = ((a % m) + (b % m)) % m;
  res %= m;
  return res;
}
long long mul(long long a, long long b, long long m) {
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = ((a % m) * (b % m)) % m;
  res %= m;
  return res;
}
long long sub(long long a, long long b, long long m) {
  long long res = (a - b + m) % m;
  res %= m;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(1000, 0), b(m);
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[x] = 1;
    }
    for (long long i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (auto x : b) {
      if (a[x] == 1) {
        cout << "YES\n";
        cout << "1 " << x << '\n';
        goto yaha;
      }
    }
    cout << "NO\n";
  yaha:;
  }
  return 0;
}
