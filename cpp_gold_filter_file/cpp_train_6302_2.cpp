#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k;
  while (scanf("%d", &n) != EOF) {
    if (n <= 9) {
      printf("%d\n", n);
      continue;
    } else if (n > 9 && n <= 189) {
      n -= 9;
      i = n % 2;
      n /= 2;
      if (i) {
        printf("%d\n", n / 10 + 1);
        continue;
      } else {
        printf("%d\n", (n + 9) % 10);
        continue;
      }
    } else {
      n -= 189;
      i = n % 3;
      n /= 3;
      if (i == 1) {
        printf("%d\n", n / 100 + 1);
        continue;
      } else if (i == 2) {
        printf("%d\n", n / 10 % 10);
        continue;
      } else {
        printf("%d\n", (n + 9) % 10);
        continue;
      }
    }
  }
  return 0;
}
