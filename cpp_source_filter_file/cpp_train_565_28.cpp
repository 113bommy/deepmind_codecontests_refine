#include <bits/stdc++.h>
char a[1500];
int main(void) {
  int n, i, cntT, j, max, cnt;
  while (scanf("%d", &n) != EOF) {
    getchar();
    cnt = 0;
    for (i = 0; i < n; i++) {
      a[i] = getchar();
      if (a[i] == 'T') cnt++;
    }
    max = 0;
    for (i = 0; i < n; i++) {
      cntT = 0;
      for (j = 0; j < cnt; j++) {
        if (a[i + j] == 'T') cntT++;
      }
      if (cntT > max) max = cntT;
    }
    printf("%d\n", cnt - max);
  }
  return 0;
}
