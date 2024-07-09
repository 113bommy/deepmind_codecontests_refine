#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 214748364;
const long long linf = 1e18 + 5;
const double PI = acos(-1.0);
const int MAXN = 105;
const int N = 100;
const int fix = 1e5;
const int K = 30;
long long M = 1e9 + 7;
int n;
map<map<char, int>, int> a, b;
void q(int l, int r) {
  cout << "? " << l << " " << r << endl;
  cout.flush();
}
int work() {
  cin >> n;
  if (n == 1) {
    q(1, 1);
    string t;
    cin >> t;
    cout << "! " << t << endl;
    cout.flush();
  } else {
    q(1, n);
    for (register int i = (1), I = ((n - 1) * n / 2 + n) + 1; i < I; ++i) {
      string t;
      cin >> t;
      map<char, int> tt;
      for (auto c : t) tt[c]++;
      a[tt]++;
    }
    q(2, n);
    for (register int i = (1), I = ((n - 2) * (n - 1) / 2 + n - 1) + 1; i < I;
         ++i) {
      string t;
      cin >> t;
      map<char, int> tt;
      for (auto c : t) tt[c]++;
      b[tt]++;
    }
    map<char, int> len[105], cur;
    for (auto x : a)
      if (a[x.first] != b[x.first]) {
        int ll = 0;
        for (auto y : x.first) ll += y.second;
        len[ll] = x.first;
      }
    string ans;
    for (register int i = (1), I = (n) + 1; i < I; ++i) {
      for (auto x : cur) len[i][x.first] -= x.second;
      for (auto x : len[i])
        if (x.second) ans.push_back(x.first), cur[x.first]++;
    }
    cout << "! " << ans << endl;
    cout.flush();
  }
  return 0;
}
int main() {
  work();
  return 0;
}
