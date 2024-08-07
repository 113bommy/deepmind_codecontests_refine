#include <bits/stdc++.h>
using namespace std;
int val;
int deg[100005];
int x[100005], n;
vector<int> q;
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &deg[i], &x[i]);
    if (deg[i] == 1) {
      q.push_back(i);
    }
  }
  int it = 0;
  while (it < q.size()) {
    int v = q[it++];
    if (deg[v] == 0) continue;
    if (deg[v] != 1) return 1;
    ans.push_back(make_pair(v, x[v]));
    int val = x[v];
    x[val] ^= v;
    deg[val]--;
    if (deg[val] == 1) {
      q.push_back(val);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
