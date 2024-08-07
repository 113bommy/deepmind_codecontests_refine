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
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = (int)1e9 + 7;
const long long llinf = (long long)1e18 + 5;
const long double pi = acos(-1.0);
vector<int> a[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> c[i];
    a[p[i]].push_back(c[i]);
  }
  for (int i = 1; i <= m; ++i) {
    sort(a[i].begin(), a[i].end());
  }
  long long res = llinf;
  for (int x = 1; x <= n; ++x) {
    vector<int> ptr(m + 1);
    long long need = 0;
    int total = 0;
    vector<int> aa;
    for (int i = 2; i <= n; ++i) {
      int extra = max(0, (int)a[i].size() - (x - 1));
      for (int j = 0; j < extra; ++j) {
        need += a[i][j];
        total++;
      }
      for (int j = extra; j < a[i].size(); ++j) {
        aa.push_back(a[i][j]);
      }
    }
    sort(aa.begin(), aa.end());
    int lft = max(0, x - ((int)a[1].size() + total));
    if (aa.size() < lft) continue;
    for (int j = 0; j < lft; ++j) need += aa[j];
    res = min(res, need);
  }
  cout << res << endl;
  return 0;
}
