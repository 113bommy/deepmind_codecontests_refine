#include <bits/stdc++.h>
using namespace std;
int T;
double n, x, y, z;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lf", &n);
    if (n > 1e-7 && n + 1e-7 < 4.0)
      printf("N\n");
    else {
      z = sqrt(n * n - n * 4);
      x = (n + z) / 2.0;
      y = n - x;
      printf("Y %.12f %.12f\n", x, y);
    }
  }
  return 0;
}
