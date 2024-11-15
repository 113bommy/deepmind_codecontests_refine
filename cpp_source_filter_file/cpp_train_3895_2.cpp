#include <bits/stdc++.h>
using namespace std;
const int max_n = 1, inf = 1e9 + 100;
bool solve(long long a, long long n, long long p, long long h) {
  if (h == 0) {
    return false;
  }
  a %= p;
  if (a * n < p) {
    return h >= a;
  }
  if (a * n < 1e3) {
    vector<int> v;
    long long cur = a;
    for (int i = 0; i < n; ++i) {
      v.push_back(cur);
      cur += a;
      if (cur > p) {
        cur -= p;
      }
    }
    sort(v.begin(), v.end());
    if (v[0] > h) {
      return false;
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (v[i + 1] - v[i] > h) {
        return false;
      }
    }
    return true;
  }
  long long a1 = min(p % a, a - p % a);
  long long n1 = (n * a / p);
  if ((n * a) % p + a < p) {
    --n1;
  }
  long long p1 = a;
  if (a1 * n1 < p1) {
    return h >= max(a1, p1 - a1 * n1);
  }
  return solve(a1, n1, p1, h);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, n, p, h;
    cin >> a >> n >> p >> h;
    cout << (solve(a, n, p, h) ? "YES" : "NO") << "\n";
  }
  return 0;
}
