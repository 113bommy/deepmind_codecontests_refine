#include <bits/stdc++.h>
int main() {
  double x;
  int a, h;
  double mind = 100000;
  int mina, minh;
  scanf("%lf", &x);
  for (h = 1; h <= 10; h++) {
    for (a = 1; a <= 10; a++) {
      double r;
      r = (double)(a * a * h * h);
      r /= (double)(a * a + 4.0 * h * h);
      r = sqrt(r);
      r = (double)((int)(r * 1000000 + 0.5)) / 1000000;
      if (r >= x && r - x < mind) {
        mind = r - x;
        mina = a;
        minh = h;
      }
    }
  }
  printf("%d %d\n", mina, minh);
}
