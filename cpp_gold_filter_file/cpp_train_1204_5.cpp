#include <bits/stdc++.h>
using namespace std;
bool dbg = 0;
clock_t start_time = clock();
void bad(string mes = "Impossible") {
  cout << mes;
  exit(0);
}
void bad(int mes = -1) {
  cout << mes;
  exit(0);
}
template <typename T>
string bin(T x, int st = 2) {
  string ans = "";
  while (x > 0) {
    ans += char('0' + x % st);
    x /= st;
  }
  reverse(ans.begin(), ans.end());
  return ans.empty() ? "0" : ans;
}
template <typename T>
void amax(T& x, T y) {
  x = max(x, y);
}
template <typename T>
void amin(T& x, T y) {
  x = min(x, y);
}
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) {
    c = getchar();
  }
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T>
void read(T& a, T& b) {
  read(a), read(b);
}
template <typename T>
void read(T& a, T& b, T& c) {
  read(a, b), read(c);
}
template <typename T>
void read(T& a, T& b, T& c, T& d) {
  read(a, b), read(c, d);
}
const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = 1e9 + 7;
const long long llinf = 4e18 + 5;
template <typename T>
T binpow(T n, T second) {
  if (second <= 0) return 1LL;
  if (second % 2 == 0) {
    T b = binpow(n, second / 2);
    return (1LL * b * b) % base;
  } else {
    return (1LL * binpow(n, second - 1) * n) % base;
  }
}
int cnt[maxn];
int main() {
  int n;
  read(n);
  for (int i = 0; i < n; i++) {
    int x;
    read(x);
    cnt[x]++;
  }
  int ans = 1;
  for (int g = 2; g < maxn; g++) {
    int cur = 0;
    for (int i = g; i < maxn; i += g) cur += cnt[i];
    amax(ans, cur);
  }
  cout << ans;
  return 0;
}
