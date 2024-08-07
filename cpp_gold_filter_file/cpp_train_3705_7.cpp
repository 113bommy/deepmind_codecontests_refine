#include <bits/stdc++.h>
using namespace std;
const int MAXR = 100000000;
set<int> s, v, h;
int Query(const int &x, const int &y) {
  int ret;
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &ret);
  return ret;
}
void BSearch(const int &l, const int &r) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int val = Query(mid, mid);
  if (val == 0) s.insert(mid), val++;
  BSearch(l, mid - val);
  BSearch(mid + val, r);
  return;
}
int main() {
  int f;
  BSearch(-MAXR, MAXR);
  for (f = -MAXR; s.count(f) > 0; ++f)
    ;
  for (auto &x : s) {
    if (Query(x, f) == 0) v.insert(x);
    if (Query(f, x) == 0) h.insert(x);
  }
  printf("1 %d %d\n", v.size(), h.size());
  for (auto &x : v) printf("%d ", x);
  printf("\n");
  for (auto &x : h) printf("%d ", x);
  printf("\n");
  fflush(stdout);
  return 0;
}
