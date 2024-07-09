#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const long double E = 1e-9;
unsigned char ccc;
bool _minus = false;
template <typename T>
inline T sqr(T t) {
  return (t * t);
}
inline void read(long long &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
inline void read(int &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
char wwww[19];
int kkkk;
inline void write(long long y) {
  long long x = y;
  kkkk = 0;
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (!x)
    ++kkkk, wwww[kkkk] = '0';
  else
    while (x) {
      ++kkkk;
      wwww[kkkk] = char(x % 10 + '0');
      x /= 10;
    }
  for (int i = kkkk; i >= 1; --i) putchar(wwww[i]);
}
int n;
const int MAX = 5000;
vector<int> vec[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  srand(time(NULL));
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    long long a, x, y, m;
    cin >> k >> a >> x >> y >> m;
    vec[i].push_back(a);
    while ((int)vec[i].size() < k) {
      a = (a * x + y) % m;
      vec[i].push_back(a);
    }
    reverse(vec[i].begin(), vec[i].end());
  }
  bool ok = true;
  vector<pair<int, int> > ans;
  int _ans = -1;
  while (ok) {
    _ans++;
    vector<pair<int, int> > res;
    ok = false;
    for (int i = 0; i < n; i++) {
      if (!vec[i].empty()) {
        int val = vec[i].back();
        res.push_back(make_pair(val, i + 1));
        vec[i].pop_back();
        while (!vec[i].empty() && vec[i].back() >= val) {
          val = vec[i].back();
          vec[i].pop_back();
          res.push_back(make_pair(val, i + 1));
        }
        if (!vec[i].empty()) ok = true;
      }
    }
    sort(res.begin(), res.end());
    ans.insert(ans.end(), res.begin(), res.end());
  }
  cout << _ans << "\n";
  for (pair<int, int> a : ans) {
    cout << a.first << " " << a.second << "\n";
  }
}
