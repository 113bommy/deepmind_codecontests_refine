#include <bits/stdc++.h>
using namespace std;
int n, m, f[4000002], r = 0, sv_r[2000002], sv_l[2000002];
char s[2000001], x[4000002];
long long ans = 0, sum = 0, mod = 51123987;
int main() {
  scanf("%d%s", &n, s);
  m = 2 * n;
  for (int i = 0; i < m; i++) x[i] = '$';
  for (int i = 0; i < n; i++) x[2 * i] = s[i];
  m--;
  x[m] = '!';
  for (int i = 0; i < m; i++) {
    if (r + f[r] >= i) f[i] = min(f[2 * r - i], f[r] + r - i);
    while (f[i] + i >= f[r] + r && i - f[i] - 1 >= 0 &&
           x[f[i] + i + 1] == x[i - f[i] - 1])
      f[i]++;
    if (f[i] + i >= f[r] + r) r = i;
    if (x[i] == '$') {
      sv_r[i / 2 + 1]++, sv_r[i / 2 + 1 + (f[i] + 1) / 2]--;
      if (f[i] != 0) sv_l[i / 2 - (f[i] - 1) / 2]++, sv_l[i / 2 + 1]--;
    } else {
      sv_r[i / 2]++, sv_r[i / 2 + f[i] / 2 + 1]--;
      sv_l[i / 2 - f[i] / 2]++, sv_l[i / 2 + 1]--;
    }
  }
  for (int i = 1; i < n; i++) sv_r[i] += sv_r[i - 1], sv_l[i] += sv_l[i - 1];
  for (int i = 0; i < n; i++) {
    ans += 1ll * sum * sv_l[i];
    ans %= mod;
    ans += (1ll * sv_l[i] * (sv_l[i] - 1)) / 2ll;
    ans %= mod;
    sum += sv_l[i] - sv_r[i];
    sum = (sum + mod) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
