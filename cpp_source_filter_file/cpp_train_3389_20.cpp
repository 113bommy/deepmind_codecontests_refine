#include <bits/stdc++.h>
int main() {
  int k = 0, n, m, j, i;
  char a[100000];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n * m + 2; i++) {
    scanf("%c", &a[i]);
  }
  for (j = 0; j < n * m + 2; j++) {
    if (a[j] == 'C' || a[j] == 'M' || a[j] == 'Y') k = 1;
  }
  if (k == 1) {
    printf("#Color");
  } else {
    printf("#Black&White");
  }
}
