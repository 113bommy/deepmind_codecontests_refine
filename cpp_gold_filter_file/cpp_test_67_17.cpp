#include <bits/stdc++.h>
const int mod = 1000000007;
const int gmod = 3;
const int inf = 1039074182;
const double eps = 1e-9;
const double pi = 3.141592653589793238462643383279;
const long long llinf = 2LL * inf * inf;
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
inline void chadd(int &x, int b) {
  x += b - mod;
  x += (x >> 31 & mod);
}
template <typename T1, typename T2>
inline void chadd(T1 &x, T2 b) {
  x += b;
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void chmul(T1 &x, T2 b) {
  x = 1LL * x * b % mod;
}
template <typename T1, typename T2>
inline void chmod(T1 &x, T2 b) {
  x %= b, x += b;
  if (x >= b) x -= b;
}
template <typename T>
inline T mabs(T x) {
  return (x < 0 ? -x : x);
}
using namespace std;
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, const vector<T> &vec) {
  cout << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << vec[i];
    if (i != (int)vec.size() - 1) cout << ',';
  }
  cout << "}";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p) {
  cout << "(" << p.first << ',' << p.second << ")";
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, queue<T> q) {
  vector<T> t;
  while (q.size()) {
    t.push_back(q.front());
    q.pop();
  }
  cout << t;
  return cout;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m) {
  for (auto &x : m) {
    cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
  }
  return cout;
}
template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, const pair<T1, T2> y) {
  x.first += y.first;
  x.second += y.second;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x) {
  return make_pair(-x.first, -x.second);
}
template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec) {
  vector<vector<T>> v;
  int n = vec.size(), m = vec[0].size();
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = vec[j][i];
    }
  }
  return v;
}
void print0x(int x) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
template <typename T>
void print0x(T x, int len) {
  std::vector<int> vec;
  while (x) {
    std::cout << (x & 1);
    x >>= 1;
    len--;
  }
  while (len--) cout << 0;
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
using namespace std;
int n;
long double p;
int main() {
  cin >> n >> p;
  for (int i = 0; i <= n; i++) {
    long double s = 0;
    for (int j = 1; j <= 3; j++) {
      int s0 = j, s1 = 3 - j;
      long double p = 1;
      for (int k = n; k >= n - 2; k--) p /= (long double)k / (n - k + 1);
      for (int k = i; k > i - s0; k--) p *= (long double)k / (i - k + 1);
      for (int k = n - i; k > n - i - s1; k--)
        p *= (long double)k / (n - i - k + 1);
      s += p * (j == 1 ? 0.5 : 1.0);
    }
    if (s + 1e-12 >= p) {
      cout << i << endl;
      exit(0);
    };
  }
  return 0;
}
