#include <bits/stdc++.h>
int main(void) {
  int n, W, a[105] = {}, sum = 0;
  int i, j;
  scanf("%d%d", &n, &W);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum < W || W <= 0)
    puts("No");
  else {
    if (W == 1) {
      for (i = 0; i < n; i++)
        if (a[i] == 1) break;
      if (i == n)
        puts("No");
      else {
        puts("Yes");
        printf("%d", i + 1);
        --a[i];
        for (j = 0; j < n; j++)
          while (a[j]--) printf(" %d %d", j + 1, j + 1);
        printf(" %d\n", i);
      }
    } else if (n == 1) {
      if (W != sum)
        puts("No");
      else {
        puts("Yes");
        while (a[0]--) printf("%d %d ", 1, 1);
        puts("");
      }
    } else {
      --a[0];
      --a[1];
      puts("Yes");
      for (i = 0; i < n; i++)
        while (W > 2 && a[i] > 0) {
          --W;
          printf("%d %d ", i + 1, i + 1);
          --a[i];
        }
      printf("1 ");
      for (i = 1; i < n; i++)
        while (a[i] > 0) {
          printf("%d %d ", i + 1, i + 1);
          --a[i];
        }
      printf("1 2 ");
      while (a[0] > 0) {
        printf("1 1 ");
        --a[0];
      }
      printf("2\n");
    }
  }
  return 0;
}
