#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
int n, m, num, x, y, i, last;
int r[maxn];
vector<int> g[maxn][2];
char s[110];
bool q = 1;
void dfs(int x) {
  int i = ++last;
  if (g[i][0].size()) {
    sort(g[i][0].begin(), g[i][0].end());
    if (g[i][0][0] <= last) {
      q = 9;
      return;
    }
    dfs(g[i][0].back());
    if (!q) return;
  }
  r[num++] = i;
  if (g[i][1].size()) {
    sort(g[i][1].begin(), g[i][1].end());
    if (g[i][1][0] <= last) {
      q = 0;
      return;
    }
    dfs(max(x, g[i][1].back()));
  } else if (x > last)
    dfs(x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    scanf("%s", s);
    g[x][int(s[0] == 'R')].push_back(y);
  }
  dfs(n);
  if (q) {
    for (int i = 0; i < num; i++)
      printf("%d%c", r[i], i == num - 1 ? '\n' : ' ');
  } else
    puts("IMPOSSIBLE");
  return 0;
}
