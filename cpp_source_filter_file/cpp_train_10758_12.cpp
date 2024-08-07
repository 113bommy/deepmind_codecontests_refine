#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000013;
char s[maxn], ans[maxn];
int n, j, m, ha[maxn], pw[maxn], f[maxn];
bool check(int y, int L) {
  int x = y - L;
  if (x < 0) return 1;
  return (ha[y] - ha[x] * pw[L]) * pw[x + 1] != f[y] - f[x];
}
void dfs(int t, bool beyond) {
  if (t > n) {
    puts(ans + 1);
    exit(0);
  }
  for (char i = beyond ? 'a' : s[t]; i <= 'z'; i++) {
    ans[t] = i;
    f[t] = f[t - 1] + i * pw[t];
    ha[t] = ha[t - 1] * maxn + i;
    if (check(t, m) && check(t, m + 1)) dfs(t + 1, beyond || i > s[t]);
  }
}
int main() {
  scanf("%d%s", &m, s + 1);
  j = n = strlen(s + 1);
  while (j && s[j] == 'z') s[j--] = 'a';
  if (!j) return puts("Impw[ossible"), 0;
  s[j]++, pw[0] = 1;
  for (j = 1; j <= n; j++) pw[j] = pw[j - 1] * maxn;
  dfs(1, 0);
  puts("Impossible");
  return 0;
}
