#include <bits/stdc++.h>
long long n, t, ans = 0, k;
long long a[111], cnk[111][111];
long long turn(long long t) {
  long long i = 0;
  if (t & (t - 1)) return -1;
  while (t >>= 1) i++;
  return i;
}
int main() {
  int i, j, l;
  a[0] = 1;
  for (i = 1; i < 63; i++) a[i] = a[i - 1] << 1;
  memset(cnk, 0, sizeof(cnk));
  for (i = 0; i < 111; i++) {
    cnk[i][0] = 1;
    for (j = 1; j <= i; j++) cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
  }
  scanf("%I64d%I64d", &n, &t);
  k = turn(t);
  if (k == -1) {
    printf("0\n");
    return 0;
  }
  for (i = 1; n > a[i]; i++) {
    ans += cnk[i][k];
    n -= a[i];
  }
  for (i = 62; i > 0; i--)
    if ((~k) && (n >> i & 1)) {
      ans += cnk[i][k];
      k--;
    }
  printf("%I64d\n", ans);
  return 0;
}
