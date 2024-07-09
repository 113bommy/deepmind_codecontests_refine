#include <bits/stdc++.h>
using namespace std;
struct road {
  int s, e, v;
};
bool cmp(road a, road b) { return a.v < b.v; }
int main() {
  int n, m;
  cin >> n >> m;
  set<int> air;
  set<int> fac;
  road r[m];
  for (int i = 0; i < m; i++) {
    cin >> r[i].s >> r[i].e >> r[i].v;
  }
  sort(r, r + m, cmp);
  bool ok = false;
  for (int i = 0; i < m; i++) {
    air.insert(r[i].s);
    fac.insert(r[i].e);
    if (air.size() == n && fac.size() == n) {
      ok = true;
      cout << r[i].v << endl;
      break;
    }
  }
  if (!ok) cout << -1 << endl;
  return 0;
}
