#include <bits/stdc++.h>
int main(void) {
  int a[4];
  for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
  while (a[0] > 1 || a[1] > 1 || a[2] > 1 || a[3] > 1) {
    int f = 0;
    for (int i = 0; i < 4; i++) {
      if (a[i] % 2 == 0 && (a[(i + 1) % 4] % 2 == 0)) {
        printf("/%d\n", i + 1);
        a[i] /= 2;
        a[(i + 1) % 4] /= 2;
        f = 1;
        break;
      }
    }
    if (f) continue;
    for (int i = 0; i < 4; i++)
      if ((a[i] % 2) && (a[(i + 1) % 4] % 2) &&
          (a[i] > 1 || a[(i + 1) % 4] > 1)) {
        f = 1;
        printf("+%d\n", i + 1);
        a[i]++;
        a[(i + 1) % 4]++;
        break;
      }
    if (f) continue;
    for (int i = 0; i < 4; i++)
      if (a[i] >= a[0] && a[i] >= a[1] && a[i] >= a[2] && a[i] >= a[3]) {
        printf("+%d\n", i + 1);
        a[i]++;
        a[(i + 1) % 4]++;
        break;
      }
  }
  return 0;
}
