#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
vector<int> t[maxN];
int ca[maxN][2];
int d[maxN], tp[maxN], sl[maxN], n, m;
vector<int> ke[maxN];
void update(int k, int i, int s) {
  while (i <= sl[k]) {
    t[k][i] += s;
    i += i & (-i);
  }
}
int getans(int k, int i) {
  int ans = 0;
  while (i > 0) {
    ans += t[k][i];
    i -= i & (-i);
  }
  return ans;
}
void dfs(int u, int pre) {
  ++sl[tp[u]];
  t[tp[u]].push_back(0);
  for (int i = 0; i < ke[u].size(); i++)
    if (ke[u][i] != pre) {
      d[ke[u][i]] = d[u] + 1;
      tp[ke[u][i]] = tp[u];
      dfs(ke[u][i], u);
    }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%i%i", &u, &v);
    ca[i][0] = u;
    ca[i][1] = v;
    ke[u].push_back(v);
    ke[v].push_back(u);
  }
  int goc = 1;
  for (int i = 1; i <= n; i++)
    if (ke[i].size() > ke[goc].size()) goc = i;
  for (int i = 0; i < ke[goc].size(); i++) {
    tp[ke[goc][i]] = i;
    d[ke[goc][i]] = 1;
    t[i].push_back(0);
    sl[i] = 0;
    dfs(ke[goc][i], goc);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    char ch;
    int u, v;
    scanf("%i", &ch);
    if (ch < 3) {
      int tt;
      scanf("%i", &tt);
      u = ca[tt][0];
      v = ca[tt][1];
    } else
      scanf("%i%i", &u, &v);
    if (d[u] > d[v]) swap(u, v);
    if (ch == 1) {
      update(tp[v], d[v], 0);
    } else if (ch == 2) {
      update(tp[v], d[v], 1);
    } else {
      if (tp[u] == tp[v]) {
        if (getans(tp[v], d[v]) - getans(tp[u], d[u]) == 0)
          printf("%i\n", d[v] - d[u]);
        else
          cout << "-1\n";
      } else {
        if (getans(tp[v], d[v]) + getans(tp[u], d[u]) == 0)
          printf("%i\n", d[u] + d[v]);
        else
          cout << "-1\n";
      }
    }
  }
  fclose(stdin);
  return 0;
}
