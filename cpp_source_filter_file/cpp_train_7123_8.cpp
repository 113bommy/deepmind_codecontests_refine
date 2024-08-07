#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 4, sq = 500;
int n, m, q, ans[N], adr[N], cnt;
bool is_on[N], is_big[N];
bitset<sq> has[N];
set<int> s[N];
vector<int> big;
inline void check(int v) {
  if (s[v].size() > sq) {
    is_big[v] = true;
    adr[v] = big.size();
    big.push_back(v);
    for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it++) {
      if (is_on[*it]) ans[v]++;
      has[*it][adr[v]] = true;
    }
  }
}
inline void add_edge(int u, int v) {
  s[v].insert(u);
  if (is_big[v]) {
    ans[v] += is_on[u];
    has[u][adr[v]] = true;
  } else
    check(v);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int o;
  scanf("%d", &o);
  for (int i = 0, x; i < o; i++) {
    scanf("%d", &x);
    is_on[x - 1] = true;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u - 1, v - 1);
    add_edge(v - 1, u - 1);
  }
  while (q--) {
    char c[2];
    int v, u;
    scanf("%s", c);
    if (c[0] == 'O' || c[0] == 'F') {
      scanf("%d", &v);
      v--;
      is_on[v] = !is_on[v];
      for (int i = 0; i < big.size(); i++)
        if (has[v][i]) ans[big[i]] += (c[0] == 'O' ? 1 : -1);
    } else if (c[0] == 'A') {
      scanf("%d%d", &v, &u);
      add_edge(u - 1, v - 1);
      add_edge(v - 1, u - 1);
    } else if (c[0] == 'D') {
      scanf("%d%d", &u, &v);
      u--, v--;
      s[u].erase(v), s[v].erase(u);
      if (is_big[u]) {
        ans[u] -= is_on[v];
        has[v][adr[u]] = false;
      }
      if (is_big[v]) {
        ans[v] -= is_on[u];
        has[u][adr[v]] = false;
      }
    } else {
      cnt++;
      scanf("%d", &v);
      v--;
      if (is_big[v])
        printf("%d\n", ans[v]);
      else {
        int res = 0;
        for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it++)
          if (is_on[*it]) res++;
        printf("%d\n", res);
      }
    }
  }
  return 0;
}
