#include <bits/stdc++.h>
int f[66];
int main() {
  int a;
  scanf("%d", &a);
  f[1] = 3;
  f[2] = 3;
  f[3] = 1;
  f[4] = 2;
  f[5] = 2;
  printf("%d\n", f[a]);
  return 0;
}
