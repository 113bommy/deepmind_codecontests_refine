#include <bits/stdc++.h>
int a[410], n, i, j, k, K, Ans, Now, Cnt;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  Ans = 2000000000;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      K = a[i] - 1;
      Cnt = 1;
      for (k = i + 1; k <= j; k++) {
        Cnt += K / a[k];
        K %= a[k];
      }
      Now = K = a[i] - 1 - K + a[j];
      for (k = 0; k < n; k++) {
        Cnt -= K / a[k];
        K %= a[k];
      }
      if (Cnt < 0 && Now < Ans) Ans = Now;
    }
  if (Ans == 2000000000)
    printf("-1\n");
  else
    printf("%d\n", Ans);
  return 0;
}
