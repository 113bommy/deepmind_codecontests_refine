#include <bits/stdc++.h>
using namespace std;
int a[150][5];
int main() {
  int n, i, j, q;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= 4; j++) a[i][j] = 0;
  }
  a[1][1] = 1;
  a[1][2] = 1;
  q = 2;
  for (i = 1; i <= n - 1; i++) {
    for (j = 1; j <= 4; j++)
      if (a[i][j] == 0) {
        a[i][j] = q;
        a[i + 1][j] = q;
        q++;
      }
  }
  for (j = 1; j <= 4; j++)
    if (a[n][j] == 0) a[n][j] = q;
  for (j = 1; j <= 4; j++) {
    for (i = 1; i <= n; i++) printf("%c", 'a' + (a[i][j] - 1) % 26);
    printf("\n");
  }
}
