#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, mod = 1e9 + 7;
template <int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator+(modint<MOD> other) const {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  inline modint<MOD> operator-(modint<MOD> other) const {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> operator*(modint<MOD> other) const {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> &operator+=(modint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD) this->value -= MOD;
    return *this;
  }
  inline modint<MOD> &operator-=(modint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> &operator*=(modint<MOD> other) {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> operator-() const {
    return modint<MOD>(this->value ? MOD - this->value : 0);
  }
  modint<MOD> pow(uint64_t k) const {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1) {
      if (k & 1) y *= x;
      x *= x;
    }
    return y;
  }
  modint<MOD> inv() const { return pow(MOD - 2); }
  inline modint<MOD> operator/(modint<MOD> other) const {
    return *this * other.inv();
  }
  inline modint<MOD> operator/=(modint<MOD> other) {
    return *this *= other.inv();
  }
  inline bool operator==(modint<MOD> other) const {
    return value == other.value;
  }
  inline bool operator!=(modint<MOD> other) const {
    return value != other.value;
  }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) {
  return modint<MOD>(value) * n;
}
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) {
  return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD>
istream &operator>>(istream &in, modint<MOD> &n) {
  return in >> n.value;
}
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) {
  return out << n.value;
}
using mint = modint<mod>;
vector<mint> BerlekampMassey(vector<mint> S) {
  int n = (int)S.size(), L = 0, m = 0;
  vector<mint> C(n), B(n), T;
  C[0] = B[0] = 1;
  mint b = 1;
  for (int i = 0; i < n; i++) {
    ++m;
    mint d = S[i];
    for (int j = 1; j <= L; j++) d += C[j] * S[i - j];
    if (d == 0) continue;
    T = C;
    mint coef = d * b.inv();
    for (int j = m; j < n; j++) C[j] -= coef * B[j - m];
    if (2 * L > i) continue;
    L = i + 1 - L;
    B = T;
    b = d;
    m = 0;
  }
  C.resize(L + 1);
  C.erase(C.begin());
  for (auto &x : C) x *= -1;
  return C;
}
vector<mint> combine(int n, vector<mint> &a, vector<mint> &b,
                     vector<mint> &tr) {
  vector<mint> res(n * 2 + 1, 0);
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) res[i + j] += a[i] * b[j];
  }
  for (int i = 2 * n; i > n; --i) {
    for (int j = 0; j < n; j++) res[i - 1 - j] += res[i] * tr[j];
  }
  res.resize(n + 1);
  return res;
};
mint LinearRecurrence(vector<mint> &S, vector<mint> &tr, long long k) {
  int n = S.size();
  assert(n == (int)tr.size());
  if (k < 0LL) return mint(0);
  if (n == 0) return 0;
  if (k < n) return S[k];
  vector<mint> pol(n + 1), e(pol);
  pol[0] = e[1] = 1;
  for (++k; k; k /= 2) {
    if (k % 2) pol = combine(n, pol, e, tr);
    e = combine(n, e, e, tr);
  }
  mint res = 0;
  for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
  return res;
}
mint z_match(string s, int x) {
  int n = (int)s.length();
  vector<int> z(n);
  int ans = 0;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    else
      z[i] = 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    if (z[i] == x) ans++;
  }
  return mint(ans);
}
void solve() {
  vector<string> v;
  v.push_back("a");
  v.push_back("b");
  vector<mint> sha, shb, shab, shba, shbb;
  for (int i = 1; i <= 10; i++) {
    v.push_back(v[i] + v[i - 1]);
    sha.push_back(z_match("a#" + v.back(), 1));
    shb.push_back(z_match("b#" + v.back(), 1));
    shab.push_back(z_match("ab#" + v.back(), 2));
    shba.push_back(z_match("ba#" + v.back(), 2));
    shbb.push_back(z_match("bb#" + v.back(), 2));
  }
  for (int i = 11; v.back().size() < 2000000; i++) {
    v.push_back(v[i] + v[i - 1]);
  }
  int k, m;
  cin >> k >> m;
  auto tra = BerlekampMassey(sha);
  auto trb = BerlekampMassey(shb);
  auto trab = BerlekampMassey(shab);
  auto trba = BerlekampMassey(shba);
  auto trbb = BerlekampMassey(shbb);
  sha.resize(tra.size());
  shb.resize(trb.size());
  shab.resize(trab.size());
  shba.resize(trba.size());
  shbb.resize(trbb.size());
  for (int j = 0; j < m; j++) {
    string s;
    cin >> s;
    if (k <= v.size())
      cout << z_match(s + "#" + v[k - 1], s.size()) << '\n';
    else {
      int idx = 0;
      for (int i = 0; i < v.size(); i++)
        if (v[i].size() >= s.size()) {
          idx = i;
          break;
        }
      mint a = z_match(s + "#" + v[idx], (int)s.size());
      mint b = z_match(s + "#" + v[idx + 1], s.size());
      mint ab = z_match(s + "#" + v[idx] + v[idx + 1], s.size()) - a - b;
      mint ba = z_match(s + "#" + v[idx + 1] + v[idx], s.size()) - a - b;
      mint bb = z_match(s + "#" + v[idx + 1] + v[idx + 1], s.size()) - b - b;
      mint ans(0);
      ans += LinearRecurrence(sha, tra, k - idx - 3) * a;
      ans += LinearRecurrence(shb, trb, k - idx - 3) * b;
      ans += LinearRecurrence(shab, trab, k - idx - 3) * ab;
      ans += LinearRecurrence(shba, trba, k - idx - 3) * ba;
      ans += LinearRecurrence(shbb, trbb, k - idx - 3) * bb;
      cout << ans << '\n';
    }
  }
}
int32_t main() {
  int t = 1;
  while (t--) solve();
}
