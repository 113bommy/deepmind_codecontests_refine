#include <bits/stdc++.h>
int main() {
  int n, a;
  scanf("%d %d", &n, &a);
  if ((a % 2) == 1) {
    printf("%d", (a / 2) + 1);
  } else {
    printf("%d", (n / 2) - (a / 2) + 1);
  }
  return 0;
}
