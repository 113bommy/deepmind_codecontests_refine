#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int cnt[30];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  a--, x--, b--, y--;
  while (1) {
    a %= n;
    b += n, b %= n;
    if (a == b) {
      cout << "YES";
      return 0;
    }
    if (a == x && b == y) break;
    if (a != x) a++;
    if (b != y) b--;
  }
  cout << "NO";
  return 0;
}
