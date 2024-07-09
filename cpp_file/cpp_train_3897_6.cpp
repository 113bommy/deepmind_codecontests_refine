#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, m;
long long s[400005], a[400005], size;
set<pair<long long, int> > second;
set<int> pos;
long long res = 0;
long long p = -1;
int main(void) {
  scanf("%d %d", &n, &m);
  int sz = 0;
  a[size++] = inf;
  for (int(i) = 0; (i) < (n); ++(i)) {
    long long x;
    scanf("%I64d", &x);
    if (sz >= 2 && x < s[sz - 1]) {
      long long first = s[0];
      long long second = s[sz - 1];
      if (p != -1) {
        a[size++] = p - s[0];
      }
      a[size++] = s[sz - 1] - s[0];
      res += a[size - 1];
      p = s[sz - 1];
    }
    if (sz && x < s[sz - 1]) {
      sz = 0;
    }
    s[sz++] = x;
  }
  if (sz >= 2) {
    long long first = s[0];
    long long second = s[sz - 1];
    if (p != -1) {
      a[size++] = p - s[0];
    }
    a[size++] = s[sz - 1] - s[0];
    res += a[size - 1];
    p = s[sz - 1];
  }
  int cnt = size / 2;
  a[size++] = inf;
  for (int(i) = 0; (i) < (size); ++(i)) {
    second.insert(make_pair(a[i], i));
    pos.insert(i);
  }
  while (cnt > m) {
    set<pair<long long, int> >::iterator it = second.begin();
    long long val = (*it).first, id = (*it).second;
    second.erase(it);
    pos.erase(id);
    res -= val;
    set<int>::iterator prv = --pos.lower_bound(id), nxt = pos.lower_bound(id);
    second.erase(make_pair(a[*prv], *prv));
    a[*prv] += a[*nxt] - val;
    second.insert(make_pair(a[*prv], *prv));
    second.erase(make_pair(a[*nxt], *nxt));
    pos.erase(*nxt);
    --cnt;
  }
  cout << res << "\n";
  return 0;
}
