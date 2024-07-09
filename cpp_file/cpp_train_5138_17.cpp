#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct uz {
  long long k, l, id, cnt;
  long long x, y, m;
  int i = 1;
  void add() {
    l = (l * x + y) % m;
    i++;
  }
} u[35];
vector<pair<long long, long long>> ans;
int main() {
  scanf("%d", &n);
  long long aa = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%lld%lld%lld%lld%lld", &u[i].k, &u[i].l, &u[i].x, &u[i].y, &u[i].m);
  }
  while (1) {
    long long start = ans.size();
    for (int(i) = 0; (i) < (int)(n); (i)++) {
      while (u[i].i <= u[i].k) {
        ans.push_back({u[i].l, i});
        u[i].add();
        if (ans.back().first > u[i].l) break;
      }
    }
    if (start == ans.size()) break;
    sort(ans.begin() + start, ans.end());
    if (start != 0) aa++;
  }
  printf("%lld\n", aa);
  if (aa <= 200000) {
    for (auto p : ans) printf("%lld %lld\n", p.first, p.second + 1);
  }
  return 0;
}
