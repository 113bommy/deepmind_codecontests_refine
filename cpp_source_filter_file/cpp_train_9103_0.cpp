#include <bits/stdc++.h>
using namespace std;
const int N(1e4 + 200);
int n, a[N], b[N], rpos[N];
struct hh {
  int a[N], lb[30], p[30];
  vector<pair<int, int> > w;
  inline void read() {
    for (int i(0); i < n; i++) scanf("%d", a + i);
  }
  inline void c_lb() {
    for (int i(0); i < n; i++)
      for (int k(29), t(a[i]); k >= 0; k--) {
        if ((t ^ lb[k]) < t) w.push_back(pair<int, int>(i, p[k])), t ^= lb[k];
        if (t >= (1 << k)) {
          lb[k] = t;
          p[k] = i;
          break;
        }
      }
  }
} x, y;
vector<pair<int, int> > w;
int main() {
  scanf("%d", &n);
  x.read();
  x.c_lb();
  y.read();
  for (int i(0); i < n; i++) {
    int t = y.a[i];
    for (int j(0); j < 30; j++) t = min(t, t ^ x.lb[j]);
    if (t) return puts("-1"), 0;
  }
  y.c_lb();
  for (int i(29); i >= 0; i--)
    if (x.lb[i]) {
      if (!y.lb[i]) {
        w.push_back(pair<int, int>(x.p[i], x.p[i]));
        continue;
      }
      int t = x.lb[i] ^ y.lb[i];
      for (int k(i - 1); k >= 0; k--)
        if ((t ^ x.lb[k]) < t) {
          w.push_back(pair<int, int>(x.p[i], x.p[k]));
          t ^= x.lb[k];
        }
    }
  memset(rpos, 0xff, sizeof(rpos));
  for (int i(0); i < 30; i++)
    if (x.lb[i]) rpos[x.p[i]] = i;
  for (int i(29); i >= 0; i--)
    if (x.lb[i] && y.lb[i]) {
      int pos;
      for (int j(0); j < n; j++)
        if (rpos[j] == i) {
          pos = j;
          break;
        }
      if (pos == y.p[i]) continue;
      w.push_back(pair<int, int>(pos, y.p[i]));
      w.push_back(pair<int, int>(y.p[i], pos));
      w.push_back(pair<int, int>(pos, y.p[i]));
      swap(rpos[pos], rpos[y.p[i]]);
    }
  printf("%d\n", x.w.size() + y.w.size() + w.size());
  for (int i(0); i < x.w.size(); i++)
    printf("%d %d\n", x.w[i].first + 1, x.w[i].second + 1);
  for (int i(0); i < w.size(); i++)
    printf("%d %d\n", w[i].first + 1, w[i].second + 1);
  for (int i(y.w.size() - 1); i >= 0; i--)
    printf("%d %d\n", y.w[i].first + 1, y.w[i].second + 1);
  return 0;
}
