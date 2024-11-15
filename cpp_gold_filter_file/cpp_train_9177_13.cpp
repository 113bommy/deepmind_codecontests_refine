#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1, i, j, k, n, m, sum, psz, nsz, x, mi;
  string s;
  bool ok;
  while (t--) {
    cin >> n;
    vector<long long> v(n);
    mi = 1;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x >= 0)
        v[i] = -x - 1;
      else
        v[i] = x;
      mi = min(mi, v[i]);
    };
    if (n % 2 == 0) {
      for (i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << endl;
    } else {
      ok = true;
      for (i = 0; i < n; i++) {
        if (ok == true && mi == v[i]) {
          ok = false;
          cout << -v[i] - 1 << " ";
        } else {
          cout << v[i] << " ";
        }
      }
      cout << endl;
    }
  }
}
