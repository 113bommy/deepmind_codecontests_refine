#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
template <typename T>
void ckmin(T& a, const T& b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T& a, const T& b) {
  a = max(a, b);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < (int((a).size())); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < (SZ); i++) re(a[i]);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T, bool pretty = true>
void prContain(const T& x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T& x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg& first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __algorithm {
template <typename T>
void dedup(vector<T>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
template <typename T>
typename vector<T>::iterator find(vector<T>& v, const T& x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(vector<T>& v, const T& x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename C, typename T, typename OP>
vector<T> prefixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = 0; i < (int((v).size())); i++) r[i + 1] = op(r[i], v[i]);
  return r;
}
template <typename C, typename T, typename OP>
vector<T> suffixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = (int((v).size())) - 1; i >= 0; i--) r[i] = op(v[i], r[i + 1]);
  return r;
}
}  // namespace __algorithm
using namespace __algorithm;
struct monostate {
  friend istream& operator>>(istream& is,
                             const __attribute__((unused)) monostate& ms) {
    return is;
  }
  friend ostream& operator<<(ostream& os,
                             const __attribute__((unused)) monostate& ms) {
    return os;
  }
} ms;
template <typename W = monostate>
struct wedge {
  int u, v, i;
  W w;
  wedge<W>(int _u = -1, int _v = -1, int _i = -1) : u(_u), v(_v), i(_i) {}
  int operator[](int loc) const { return u ^ v ^ loc; }
  friend void re(wedge& e) {
    re(e.u, e.v, e.w);
    --e.u, --e.v;
  }
  friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};
namespace __io {
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(15);
  if (int((second).size())) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace __io
using namespace __io;
int main() {
  setIO();
  int N;
  re(N);
  vi x(N + 2);
  re(x);
  vi d(N + 1);
  for (int i = (1); i < (N + 1); i++) re(d[i]);
  const double INF = 1e9;
  vector<pair<int, double>> left, right;
  {
    stack<pair<int, double>> stL;
    stL.push({0, INF});
    vd pref(N + 2, -1);
    pref[0] = INF;
    for (int i = (1); i < (N + 1); i++) {
      while (stL.top().second < x[i]) stL.pop();
      if (x[i] - x[stL.top().first] < 2 * d[i]) {
        pref[i] = min(x[stL.top().first] + 2. * d[i], INF);
        while (stL.top().second < pref[i]) stL.pop();
        stL.push({i, pref[i]});
      }
    }
    if (*max_element(pref.begin() + 1, pref.end() - 1) >= x.back()) {
      ps(0);
      return 0;
    }
    for (int i = 0; i < (N + 2); i++) {
      if (pref[i] > -1e-9) {
        while (!left.empty() && left.back().second < pref[i]) left.pop_back();
        left.push_back({i, pref[i]});
      }
    }
  }
  {
    stack<pair<int, double>> stR;
    stR.push({N + 1, 0});
    vd suff(N + 2, -1);
    suff[N + 1] = 0;
    for (int i = (N + 1) - 1; i >= (1); i--) {
      while (stR.top().second > x[i]) stR.pop();
      if (x[stR.top().first] - x[i] < 2 * d[i]) {
        suff[i] = max(x[stR.top().first] - 2. * d[i], 0.);
        while (stR.top().second > suff[i]) stR.pop();
        stR.push({i, suff[i]});
      }
    }
    for (int i = (N + 2) - 1; i >= 0; i--) {
      if (suff[i] > -1e-9) {
        while (!right.empty() && right.back().second > suff[i])
          right.pop_back();
        right.push_back({i, suff[i]});
      }
    }
    reverse((right).begin(), (right).end());
  }
  double ans = x.back();
  int r = 0;
  for (int l = 0; l < (int((left).size())); l++) {
    while (r < int((right).size()) && right[r].first <= left[l].first) r++;
    while (r < int((right).size()) && right[r].second > left[l].second) r++;
    if (r < int((right).size())) {
      ckmin(ans, (x[right[r].first] - x[left[l].first]) / 2.);
    }
  }
  ps(ans);
  return 0;
}
