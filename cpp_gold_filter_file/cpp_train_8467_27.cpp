#include <bits/stdc++.h>
int n;
int a[10000];
int main() {
  scanf("%d", &n);
  int i, j, k;
  a[1] = 1;
  for (i = 2; i <= 45; i++) a[i] = a[i - 1] + a[i - 2];
  for (i = 0; i <= 45; i++)
    for (j = 0; j <= 45; j++)
      for (k = 0; k <= 45; k++)
        if (a[i] + a[j] + a[k] == n) {
          printf("%d %d %d", a[i], a[j], a[k]);
          return 0;
        }
  printf("I'm too stupid to solve this problem");
}
