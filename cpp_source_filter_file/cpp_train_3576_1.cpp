#include <bits/stdc++.h>
using namespace std;
bool dp[55][55][55][55], gra[55][55];
char s[55][3];
bool dfs(int sum, int a, int b, int c) {
  if (dp[sum][a][b][c]) return 0;
  if (sum == 3 && gra[c][a] && gra[c][b]) return 1;
  if (gra[c][b] && dfs(sum - 1, c - 3, a, c)) return 1;
  if (sum >= 4 && gra[c][sum - 4] && dfs(sum - 1, c, a, b)) return 1;
  dp[sum][a][b][c] = 1;
  return 0;
}
int main(void) {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (i != j && (s[i][0] == s[j][0] || s[i][1] == s[j][1])) gra[i][j] = 1;
  if (dfs(n, n - 3, n - 2, n - 1) || n == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
