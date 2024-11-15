#include <bits/stdc++.h>
using namespace std;
const long long N = 250001;
struct driver {
  long long s, f, c, r;
};
long long n, m, a[N];
driver d[N];
bool check(long long pos, long long V) {
  if (d[pos].s < d[pos].f) {
    long long curV = V, cur = 0, cur_city = d[pos].s;
    while (cur_city != d[pos].f) {
      if (curV - (a[cur_city + 1] - a[cur_city]) * d[pos].c >= 0)
        curV -= (a[cur_city + 1] - a[cur_city]) * d[pos].c, cur_city++;
      else {
        curV = V;
        cur++;
        if (curV - (a[cur_city + 1] - a[cur_city]) * d[pos].c >= 0)
          curV -= (a[cur_city + 1] - a[cur_city]) * d[pos].c, cur_city++;
        else
          return 0;
      }
    }
    return cur <= d[pos].r;
  } else {
    long long curV = V, cur = 0, cur_city = d[pos].s;
    while (cur_city != d[pos].f) {
      if (curV - (a[cur_city] - a[cur_city - 1]) * d[pos].c >= 0)
        curV -= (a[cur_city] - a[cur_city - 1]) * d[pos].c, cur_city--;
      else {
        curV = V;
        cur++;
        if (curV - (a[cur_city] - a[cur_city - 1]) * d[pos].c >= 0)
          curV -= (a[cur_city] - a[cur_city - 1]) * d[pos].c, cur_city--;
        else
          return 0;
      }
    }
    return cur <= d[pos].r;
  }
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= m; i++) {
    long long s, f, c, r;
    cin >> s >> f >> c >> r;
    d[i] = {s, f, c, r};
  }
  random_shuffle(d + 1, d + m + 1);
  long long maxV = 0;
  for (long long i = 1; i <= m; i++) {
    if (check(i, maxV)) continue;
    long long l = maxV, r = 1000000001;
    while (l < r - 1) {
      long long mm = (l + r) / 2;
      if (check(i, mm))
        r = mm;
      else
        l = mm;
    }
    maxV = r;
  }
  cout << maxV;
  return 0;
}
