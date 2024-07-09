#include <bits/stdc++.h>
using namespace std;
int t, n, x, d, minn, maxl;
vector<int> v[1007], ed[1007];
int lv[1007];
void dfs(int x, int frm, int l = 0) {
  lv[x] = l;
  maxl = max(l, maxl);
  v[l].push_back(x);
  for (auto i : ed[x]) {
    if (i != frm) {
      dfs(i, x, l + 1);
    }
  }
}
void clr() {
  for (int i = 0; i <= 1000; i++) v[i].clear(), lv[i] = 0;
  maxl = 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    clr();
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      ed[x].push_back(y);
      ed[y].push_back(x);
    }
    dfs(1, 0);
    printf("? %d ", n);
    for (int i = 1; i <= n; i++) {
      printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d%d", &x, &minn);
    int l = lv[x] + 1, r = maxl, ans = x;
    while (l <= r) {
      int mid = (l + r) / 2;
      printf("? %d ", (int)v[mid].size());
      for (auto i : v[mid]) {
        printf("%d ", i);
      }
      printf("\n");
      fflush(stdout);
      scanf("%d%d", &x, &d);
      if (l >= r) {
        if (d == minn) ans = x;
        break;
      }
      if (d > minn)
        r = mid - 1;
      else {
        ans = x;
        l = mid + 1;
      }
    }
    clr();
    dfs(ans, 0);
    printf("? %d ", (int)v[minn].size());
    for (auto i : v[minn]) {
      printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d%d", &x, &d);
    printf("! %d %d\n", ans, x);
    fflush(stdout);
    char c[100];
    scanf("%s", c);
    for (int i = 0; i <= n; i++) ed[i].clear();
  }
  return 0;
}
