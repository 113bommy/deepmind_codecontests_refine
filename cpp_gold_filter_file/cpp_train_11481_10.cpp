#include <bits/stdc++.h>
using namespace std;
int t, n, a[500005], i, f, l, r, ans;
long long dt;
set<long long> p;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    f = 1;
    for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
    ans = 0;
    l = 1, r = 0;
    p.clear();
    for (i = 1; i <= n; ++i) {
      if (f == 1) {
        while (!p.empty()) {
          auto it = p.end();
          --it;
          if (*it + dt >= a[i])
            p.erase(it);
          else
            break;
        }
      } else {
        while (!p.empty()) {
          auto it = p.begin();
          if (-*it + dt >= a[i])
            p.erase(it);
          else
            break;
        }
      }
      r = min(r, a[i] - 1);
      if (l <= r || !p.empty()) {
        if (a[i] & 1) {
          ++ans;
          f = -f;
          dt = -dt + a[i];
          if (l <= r) {
            l = -l + a[i];
            r = -r + a[i];
            swap(l, r);
          }
        } else {
          if (l <= a[i] / 2 && a[i] / 2 <= r) {
            l = a[i] / 2;
            r = a[i] / 2;
            p.clear();
          } else if (p.find((a[i] / 2 - dt) * f) != p.end()) {
            l = a[i] / 2;
            r = a[i] / 2;
            p.clear();
          } else {
            f = -f, dt = -dt + a[i];
            p.insert((a[i] / 2 - dt) * f);
            if (l <= r) {
              l = -l + a[i];
              r = -r + a[i];
              swap(l, r);
            }
            ++ans;
          }
        }
      } else {
        f = 1, dt = 0;
        p.clear();
        if (a[i] & 1) {
          l = 1, r = a[i] - 1;
          ans += 2;
        } else {
          l = r = a[i] / 2;
          ++ans;
        }
      }
    }
    printf("%d\n", ans);
  }
}
