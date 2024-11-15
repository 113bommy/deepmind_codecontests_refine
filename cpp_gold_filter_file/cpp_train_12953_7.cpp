#include <bits/stdc++.h>
using namespace std;
int Vx[50000 + 5], Vy[50000 + 5], Vl[50000 + 5];
int Hx[50000 + 5], Hy[50000 + 5], Hl[50000 + 5];
int n, m;
struct event {
  int tp, x, y, l;
  event(int a, int b, int c, int d) { tp = a, x = b, y = c, l = d; }
  bool operator<(event P) const {
    if (x != P.x) return x < P.x;
    if (tp != P.tp) return tp < P.tp;
    return y < P.y;
  }
};
vector<event> E;
bool check(int x) {
  E.clear();
  for (int i = 0; i < n; ++i) {
    if (Vl[i] >= 2 * x) E.push_back(event(2, Vx[i], Vy[i] + x, Vl[i] - 2 * x));
  }
  for (int i = 0; i < m; ++i) {
    if (Hl[i] >= 2 * x) {
      E.push_back(event(1, Hx[i] + x, Hy[i], 0));
      E.push_back(event(3, Hx[i] + Hl[i] - x, Hy[i], 0));
    }
  }
  sort(E.begin(), E.end());
  int sz = E.size();
  set<int> S;
  set<int>::iterator it1, it2;
  for (int i = 0; i < sz; ++i) {
    if (E[i].tp == 1) S.insert(E[i].y);
    if (E[i].tp == 3) S.erase(E[i].y);
    if (E[i].tp == 2) {
      it1 = S.lower_bound(E[i].y);
      it2 = S.upper_bound(E[i].y + E[i].l);
      if (it1 != it2) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> Vx[i] >> Vy[i] >> Vl[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> Hx[i] >> Hy[i] >> Hl[i];
  }
  int lo = 0, hi = 200000000;
  if (!check(lo)) {
    puts("0");
    return 0;
  }
  while (hi - lo > 1) {
    int mi = (hi + lo) / 2;
    if (check(mi))
      lo = mi;
    else
      hi = mi;
  }
  cout << lo << endl;
}
