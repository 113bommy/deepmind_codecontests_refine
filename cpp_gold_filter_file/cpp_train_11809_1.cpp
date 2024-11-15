#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
struct node {
  int p, e;
} per[200010];
int n, k, ks;
long long ans;
bool bo[200010];
bool cmp1(node a, node b) { return a.p > b.p; }
bool cmp2(node a, node b) { return a.e < b.e; }
long long check(int p) {
  long long ans = 0;
  memset(bo, 0, sizeof(bo));
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++)
    if (per[i].p >= p - 1) cnt1++;
  cnt1 -= k - 1;
  for (int i = 1; i <= n && cnt2 < cnt1; i++) {
    if (per[i].p == p || per[i].p == p - 1) {
      ans += per[i].e;
      cnt2++;
      bo[i] = 1;
    }
  }
  for (int i = 1; i <= n && cnt2 < p; i++) {
    if (!bo[i]) {
      ans += per[i].e;
      cnt2++;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d", &per[i].p, &per[i].e);
  sort(per + 1, per + 1 + n, cmp1);
  ks = per[k].p;
  sort(per + 1, per + 1 + n, cmp2);
  ans = inf;
  for (int i = ks; i <= ks + 2; i++) {
    if (i > n) break;
    ans = min(ans, check(i));
  }
  if (ans == inf) ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
