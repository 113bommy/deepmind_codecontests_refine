#include <bits/stdc++.h>
using namespace std;
char ans[100010], s[100010];
int len;
bool dfs(int x, int y, int dep, bool same) {
  if (dep == len) {
    ans[len] = '\0';
    printf("%s\n", ans);
    return (true);
  }
  if (!same) {
    if (x) {
      ans[dep] = '4';
      return (dfs(x - 1, y, dep + 1, false));
    }
    ans[dep] = '7';
    return (dfs(x, y - 1, dep + 1, false));
  }
  if (x && s[dep] <= '4') {
    ans[dep] = '4';
    if (dfs(x - 1, y, dep + 1, s[dep] == '4')) return (true);
  }
  if (y && s[dep] <= '7') {
    ans[dep] = '7';
    if (dfs(x, y - 1, dep + 1, s[dep] == '7')) return (true);
  }
  return (false);
}
int main() {
  scanf("%s", s);
  len = strlen(s);
  if (len & 1 || !dfs(len >> 1, len >> 1, 0, true)) {
    int n = len + 1 >> 1;
    for (int i = 1; i <= n; i++) printf("4");
    for (int i = 1; i <= n; i++) printf("7");
    printf("\n");
  }
  return (0);
}
