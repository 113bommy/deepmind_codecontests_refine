#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
namespace {
const int MOD107 = 1000000007;
const int MOD998 = 998244353;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Modular {
 private:
  long long MODVALUE = 0;
  long long val = 0;
  Modular initModular(long long val) const { return Modular(val, MODVALUE); }
  inline void validate() const {}
  inline void validate(const Modular& other) const {}

 public:
  explicit operator long long() const { return val; }
  template <class T>
  Modular& operator=(const T& other) {
    val = (other % MODVALUE + MODVALUE) % MODVALUE;
    return *this;
  }
  template <class T>
  void setMod(const T& MOD) {
    MODVALUE = MOD;
  }
  Modular& operator+=(const Modular& other) {
    validate(other);
    val += other.val;
    if (val >= MODVALUE) val -= MODVALUE;
    return *this;
  }
  Modular operator+(const Modular& other) const {
    Modular tmp = *this;
    return tmp += other;
  }
  template <class T>
  Modular& operator+=(const T& other) {
    return *this += initModular(other);
  }
  template <class T>
  Modular operator+(const T& other) const {
    return *this + initModular(other);
  }
  template <class T>
  friend Modular operator+(const T& other, const Modular& m) {
    return m.initModular(other) + m;
  }
  Modular& operator++() { return *this += 1; }
  Modular operator++(int) {
    Modular tmp = *this;
    ++*this;
    return tmp;
  }
  Modular operator-() const { return initModular(-val); }
  Modular& operator-=(const Modular& other) {
    validate(other);
    val -= other.val;
    if (val < 0) val += MODVALUE;
    return *this;
  }
  Modular operator-(const Modular& other) const {
    Modular tmp = *this;
    return tmp -= other;
  }
  template <class T>
  Modular& operator-=(const T& other) {
    return *this -= initModular(other);
  }
  template <class T>
  Modular operator-(const T& other) const {
    return *this - initModular(other);
  }
  template <class T>
  friend Modular operator-(const T& other, const Modular& m) {
    return m.initModular(other) - m;
  }
  Modular& operator--() { return *this -= 1; }
  Modular operator--(int) {
    Modular tmp = *this;
    --*this;
    return tmp;
  }
  Modular& operator*=(const Modular& other) {
    validate(other);
    val *= other.val;
    val %= MODVALUE;
    if (val < 0) val += MODVALUE;
    return *this;
  }
  Modular operator*(const Modular& other) const {
    Modular tmp = *this;
    return tmp *= other;
  }
  template <class T>
  Modular& operator*=(const T& other) {
    return *this *= initModular(other);
  }
  template <class T>
  Modular operator*(const T& other) const {
    return *this * initModular(other);
  }
  template <class T>
  friend Modular operator*(const T& other, const Modular& m) {
    return m.initModular(other) * m;
  }
  Modular pow(long long power) const {
    Modular m = *this, ans = initModular(1);
    while (power) {
      if (power & 1) ans *= m;
      m *= m;
      power >>= 1;
    }
    return ans;
  }
  Modular pow(const Modular& other) const { return pow(other.val); }
  Modular inv() const { return pow(MODVALUE - 2); }
  Modular& operator/=(const Modular& other) {
    val *= other.inv().val;
    val %= MODVALUE;
    if (val < 0) val += MODVALUE;
    return *this;
  }
  Modular operator/(const Modular& other) const {
    Modular tmp = *this;
    return tmp /= other;
  }
  template <class T>
  Modular& operator/=(const T& other) {
    return *this /= initModular(other);
  }
  template <class T>
  Modular operator/(const T& other) const {
    return *this / initModular(other);
  }
  template <class T>
  friend Modular operator/(const T& other, const Modular& m) {
    return m.initModular(other) / m;
  }
  friend istream& operator>>(istream& in, Modular& m) {
    in >> m.val;
    m.val %= m.MODVALUE;
    if (m.val < 0) m.val += m.MODVALUE;
    return in;
  }
  friend ostream& operator<<(ostream& out, const Modular& m) {
    return out << m.val;
  }
  Modular() {
    val = 0;
    MODVALUE = 0;
  }
  Modular(long long val, long long MOD)
      : MODVALUE(MOD), val((val % MOD + MOD) % MOD) {}
};
using Mint = Modular;
inline ll binpow(ll b, ll p, ll mod) {
  b %= mod;
  ll ans = 1;
  for (; p > 0; p >>= 1) {
    if (p & 1) {
      ans *= b;
      ans %= mod;
    }
    b *= b;
    b %= mod;
  }
  return ans;
}
inline ll max(ll a, int b) { return (a > b ? a : b); }
inline ll max(int a, ll b) { return (a > b ? a : b); }
inline ll min(ll a, int b) { return (a < b ? a : b); }
inline ll min(int a, ll b) { return (a < b ? a : b); }
template <class T>
inline bool chkmin(T& x, const T& y) {
  return y < x ? x = y, 1 : 0;
}
template <class T>
inline bool chkmax(T& x, const T& y) {
  return x < y ? x = y, 1 : 0;
}
}  // namespace
namespace IO {
template <class T>
inline void _R(T& x) {
  cin >> x;
}
template <class T1, class T2>
inline void _R(pair<T1, T2>& x) {
  _R(x.first);
  _R(x.second);
}
template <class T>
inline void _R(vector<T>& x) {
  for (auto& i : x) _R(i);
}
template <class T>
inline void _R(deque<T>& x) {
  for (auto& i : x) _R(i);
}
inline void R() {}
template <class T1, class... T2>
inline void R(T1& x, T2&... y) {
  _R(x);
  R(y...);
}
template <class T>
inline void _W(const T& x);
template <class T1, class T2>
inline void _W(const pair<T1, T2>& p);
template <class... T>
inline void _W(const vector<T...>& x);
template <class... T>
inline void _W(const deque<T...>& x);
template <class... T>
inline void _W(const forward_list<T...>& x);
template <class... T>
inline void _W(const list<T...>& x);
template <class... T>
inline void _W(const set<T...>& x);
template <class... T>
inline void _W(const multiset<T...>& x);
template <class... T>
inline void _W(const unordered_set<T...>& x);
template <class... T>
inline void _W(const unordered_multiset<T...>& x);
template <class... T>
inline void _W(const map<T...>& x);
template <class... T>
inline void _W(const multimap<T...>& x);
template <class... T>
inline void _W(const unordered_map<T...>& x);
template <class... T>
inline void _W(const unordered_multimap<T...>& x);
template <class Container>
inline void printContainer(const Container& x) {
  bool isFirst = 1;
  for (auto i : x) {
    if (!isFirst) cout << ' ';
    isFirst = 0;
    _W(i);
  }
}
template <class T>
inline void _W(const T& x) {
  cout << x;
}
template <class T1, class T2>
inline void _W(const pair<T1, T2>& p) {
  _W(p.first);
  _W(' ');
  _W(p.second);
}
template <class... T>
inline void _W(const vector<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const deque<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const forward_list<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const list<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const set<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const multiset<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const unordered_set<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const unordered_multiset<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const map<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const multimap<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const unordered_map<T...>& x) {
  printContainer(x);
}
template <class... T>
inline void _W(const unordered_multimap<T...>& x) {
  printContainer(x);
}
inline void W() { cout << '\n'; }
template <class T>
inline void W(const T& x) {
  _W(x);
  W();
}
template <class T1, class... T2>
inline void W(const T1& x, const T2&... y) {
  _W(x);
  _W(' ');
  W(y...);
}
}  // namespace IO
using namespace IO;
namespace outputFormat {
inline string Case(int tc) { return "Case #" + to_string(tc) + ':'; }
inline string YN(bool b) { return b ? "Yes" : "No"; }
}  // namespace outputFormat
using namespace outputFormat;
namespace std {
template <class T1, class T2>
struct hash<pair<T1, T2>> {
  std::size_t operator()(pair<T1, T2> _) const {
    return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
  }
};
}  // namespace std
int main() {
  ll n, k;
  R(n, k);
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    int x;
    R(x);
    if (a.empty() && x == 0) continue;
    a.emplace_back(x);
  }
  n = a.size();
  for (int i = 0; i < n; i++)
    if (a[i] >= k) {
      W(0);
      return 0;
    }
  if (n >= 4) {
    for (int t = 1;; t++) {
      for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        chkmin(a[i], k);
      }
      if (a[n - 1] >= k) {
        W(t);
        break;
      }
    }
  } else if (n == 3) {
    ll l = 1, r = 2000000000;
    while (r > l) {
      ll t = (l + r) / 2;
      ll m = t * (t + 1) / 2;
      double estimate = 1.0 * m * a[0] + 1.0 * t * a[1] + a[2];
      bool ok = (estimate >= 2 * k);
      if (!ok) {
        ll actual = m * a[0] + t * a[1] + a[2];
        if (actual >= k) ok = 1;
      }
      if (ok)
        r = t;
      else
        l = t + 1;
    }
    W(l);
  } else if (n == 2) {
    W((k - a[1] + a[0] - 1) / a[0]);
  } else {
    assert(false);
  }
  return 0;
}
static auto __init__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  return 42;
}();
