#include <bits/stdc++.h>
int main() {
  double S;
  while (scanf("%lf", &S) != EOF) {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double s = a + b + c;
    if (s == 0) {
      printf("%.15f 0 0\n", S);
    } else {
      double k = S / s;
      a *= k;
      b *= k;
      c *= k;
      printf("%.15f %.15f %.15f\n", a, b, c);
    }
  }
  return 0;
}
