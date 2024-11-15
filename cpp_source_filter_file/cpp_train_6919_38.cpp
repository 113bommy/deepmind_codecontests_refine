#include <bits/stdc++.h>
using namespace std;
struct rect {
  int x1, x2;
  int y1, y2;
};
struct evt {
  int x1, x2;
  int y;
  bool ins;
  evt(int _x1, int _x2, int _y, bool _ins) {
    x1 = _x1;
    x2 = _x2;
    y = _y;
    ins = _ins;
  }
};
bool evt_cmp(evt e1, evt e2) {
  if (e1.y != e2.y) return e1.y < e2.y;
  return e1.ins < e2.ins;
}
int n, m, k, p = 1;
rect r[100000];
vector<evt> e;
map<int, int> xremap;
int sm[4 * 100000], cnt[4 * 100000], add[4 * 100000];
void push(int at) {
  sm[at] += add[at];
  add[2 * at] += add[at];
  add[2 * at + 1] += add[at];
  add[at] = 0;
}
void ra(int at, int lo, int hi, int qlo, int qhi, int a) {
  push(at);
  if (qlo <= lo && hi <= qhi) {
    add[at] += a;
    push(at);
    return;
  }
  if (qlo > hi || lo > qhi) {
    return;
  }
  ra(2 * at, lo, (lo + hi) / 2, qlo, qhi, a);
  ra(2 * at + 1, (lo + hi) / 2 + 1, hi, qlo, qhi, a);
  sm[at] = min(sm[2 * at + 1], sm[2 * at]);
  cnt[at] = (sm[at] == sm[2 * at] ? cnt[2 * at] : 0) +
            (sm[at] == sm[2 * at + 1] ? cnt[2 * at + 1] : 0);
}
bool sweep(int t) {
  e.clear();
  xremap.clear();
  memset(sm, 0, sizeof(sm));
  memset(cnt, 0, sizeof(cnt));
  memset(add, 0, sizeof(add));
  for (int i = 0; i < m; i++) {
    int nx1 = (r[i].x1 - 1) / t + 1, nx2 = r[i].x2 / t;
    int ny1 = (r[i].y1 - 1) / t + 1, ny2 = r[i].y2 / t;
    if (nx1 > nx2 || ny1 > ny2) continue;
    xremap[nx1] = 1;
    xremap[nx2] = 1;
    e.push_back(evt(nx1, nx2, ny1, true));
    e.push_back(evt(nx1, nx2, ny2 + 1, false));
  }
  sort(e.begin(), e.end(), evt_cmp);
  int moo = 0, last = 0, q = 1;
  for (map<int, int>::iterator it = xremap.begin(); it != xremap.end(); it++) {
    if (it->first % 2 == last % 2)
      it->second = ++(++moo);
    else
      it->second = ++moo;
    last = it->first;
  }
  while (q < moo) q *= 2;
  for (int i = q; i <= 2 * q - 1; i++) {
    sm[i] = 0;
    add[i] = 0;
    cnt[i] = 1;
  }
  for (int i = q - 1; i > 0; i--) {
    sm[i] = 0;
    add[i] = 0;
    cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
  }
  bool cur = false;
  for (int i = 0; i < (int)e.size(); i++) {
    if (e[i].ins)
      ra(1, 1, q, xremap[e[i].x1], xremap[e[i].x2], 1);
    else
      ra(1, 1, q, xremap[e[i].x1], xremap[e[i].x2], -1);
    if (i + 1 < (int)e.size() && (e[i + 1].y - e[i].y) % 2 != 0) {
      int l = cnt[1];
      int s = sm[1];
      if (s > 0) {
        cur ^= (q % 2);
      } else {
        cur ^= ((q - l) % 2);
      }
    }
  }
  return cur;
}
bool go() {
  for (int i = 1; i <= p; i *= 2) {
    if (sweep(i)) return false;
  }
  return true;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  while (p * 2 <= k) p *= 2;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
  }
  printf("%s\n", go() ? "Malek" : "Hamed");
}
