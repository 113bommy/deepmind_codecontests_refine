#include <bits/stdc++.h>
int a[1000];
int main() {
  int n, k;
  scanf("%d", &n);
  k = n - 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (i == j) {
        printf("0 ");
        a[i] = k++;
      } else
        printf("%d ", k++);
      if (k == n) k = 1;
    }
    printf("%d\n", a[i]);
    k = i + 1;
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
