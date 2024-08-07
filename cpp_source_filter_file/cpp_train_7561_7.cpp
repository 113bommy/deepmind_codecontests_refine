#include <bits/stdc++.h>
using namespace std;
template <typename T>
T getint() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * p;
}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
bool umin(T1 &x, const T2 &y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, const T2 &y) {
  if (x < y) return x = y, true;
  return false;
}
const int maxn = (int)3e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = (int)1e9 + 7;
const long long llinf = (long long)1e18 + 5;
const long double pi = acos(-1.0);
int nxt[maxn * 30][2];
int f[maxn];
int sz = 1;
int v[maxn], t[maxn];
void add(int x, int d) {
  int v = 1;
  for (int i = 29; i >= 0; --i) {
    int b = (x >> i & 1);
    if (nxt[v][b] == 0) nxt[v][b] = ++sz;
    v = nxt[v][b];
    f[v] += d;
  }
}
int get(int x) {
  int v = 1;
  int res = 0;
  for (int i = 29; i >= 0; --i) {
    int b = (x >> i & 1);
    if (f[nxt[v][b]] > 0) {
      v = nxt[v][b];
    } else {
      res |= 1 << i;
      v = nxt[v][b ^ 1];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    add(t[i], 1);
  }
  for (int i = 1; i <= n; ++i) {
    int z = get(v[i]);
    cout << z << ' ';
    add(z ^ v[i], -1);
  }
  return 0;
}
