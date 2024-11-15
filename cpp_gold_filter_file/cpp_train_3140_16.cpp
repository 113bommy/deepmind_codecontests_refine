#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, mod = 1000003;
char s[maxn];
int f[maxn];
int n, m;
int main() {
  int i, j;
  scanf("%s", s);
  n = strlen(s);
  f[0] = 1;
  for (i = 0; i < n; ++i)
    if (s[i] < '0') {
      if ((s[i] == '*' || s[i] == '/') && (!i || s[i - 1] < '0')) {
        puts("0");
        return 0;
      }
      for (++m, j = m; j > 0; --j) f[j] = f[j - 1];
      f[0] = 0;
    } else if (i && s[i - 1] < '0')
      for (j = m - 1; j >= 0; --j) f[j] = (f[j] + f[j + 1]) % mod;
  printf("%d\n", f[0]);
  return 0;
}
