#include <bits/stdc++.h>
int n;
char s[50010];
int i, j, k, m;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (i = 1; (i << 1) <= n; ++i) {
    k = 0;
    m = i;
    for (j = i + 1; j <= n; ++j) {
      if (k += s[j] ^ s[j - i] ? -k : 1 == i) {
        k = 0;
        m -= i;
      }
      s[++m] = s[j];
    }
    n = m;
  }
  s[n + 1] = 0;
  printf("%s", s + 1);
  return 0;
}
