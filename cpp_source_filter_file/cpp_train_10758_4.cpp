#include <bits/stdc++.h>
const int P = 1000000007;
const int N = 400010;
int p[N], l[N], r[N], m;
char ans[N], s[N], n;
bool ok(int i, int x) {
  if (++i < x) return 0;
  return ((r[i] - r[i - x] * p[x]) * p[i - x]) == (l[i] - l[i - x]);
}
int dfs(int i, int has) {
  if (i == n) return puts(ans), 1;
  for (ans[i] = (has ? s[i] : 'a'); ans[i] <= 'z'; ans[i]++) {
    l[i + 1] = l[i] + ans[i] * p[i];
    r[i + 1] = r[i] * P + ans[i];
    if (!ok(i, m) && !ok(i, m + 1) && dfs(i + 1, has && (s[i] == ans[i])))
      return 1;
  }
  return 0;
}
int main() {
  scanf("%d%s", &m, s);
  int i = (n = strlen(s)) - 1;
  for (; i >= 0 && s[i] == 'z'; i--) s[i] = 'a';
  if (i < 0) return puts("Impossible"), 0;
  s[i]++;
  p[0] = 1;
  for (i = 1; i < N; i++) p[i] = p[i - 1] * P;
  if (!dfs(0, 1)) puts("Impossible");
  return 0;
}
