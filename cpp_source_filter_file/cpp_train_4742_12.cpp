#include <bits/stdc++.h>
using namespace std;
char ch[150];
int main() {
  int n, m, i, j, ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("\n");
    for (j = 1; j <= m; j++) scanf("%c", &ch[j]);
  }
  for (i = 2; i <= m; i++)
    if (ch[i] != ch[i - 1] && ch[i] == 'B') {
      ans++;
    }
  printf("%d", ans);
}
