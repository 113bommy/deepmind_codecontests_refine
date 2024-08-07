#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 2.5e3 + 2;
int n;
struct Vector {
  ll x, y;
  Vector(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
  Vector operator-(const Vector &a) const {
    Vector ans;
    ans.x = x - a.x;
    ans.y = y - a.y;
    return ans;
  }
  ll operator*(const Vector &a) { return x * a.y - y * a.x; }
  bool operator<(const Vector &a) const {
    bool ck1 = x < 0 || (x == 0 && y < 0),
         ck2 = a.x < 0 || (a.x == 0 && a.y < 0);
    if (ck1 != ck2) return ck1 < ck2;
    return (x * a.y - y * a.x) > 0;
  }
} a[N];
void Read() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
}
ll C3(ll v) { return v * (v - 1) * (v - 2) / 6; }
ll C5(ll v) { return v * (v - 1) * (v - 2) * (v - 3) * (v - 4) / 120; }
void Solve() {
  ll ans(0);
  for (int i = 1; i <= n; ++i) {
    vector<Vector> s;
    for (int j = 1; j <= n; ++j)
      if (i != j) s.push_back(a[j] - a[i]);
    sort(s.begin(), s.end());
    int t = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
      while (t < j + (int)s.size() && s[j] * s[t % s.size()] >= 0) ++t;
      ans += C3(t - j - 1);
    }
  }
  cout << C5(n) * 5 - ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen(""
            ".INP",
            "r")) {
    freopen(
        ""
        ".INP",
        "r", stdin);
    freopen(
        ""
        ".OUT",
        "w", stdout);
  }
  Read();
  Solve();
}
