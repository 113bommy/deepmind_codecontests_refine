#include <bits/stdc++.h>
using namespace std;
char s[16][10] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                  "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                  "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double a[12];
int main() {
  double X, Y, Z;
  while (scanf("%lf%lf%lf", &X, &Y, &Z) != EOF) {
    long double x = X, y = Y, z = Z;
    a[0] = powl(y, z) * logl(x);
    a[1] = powl(z, y) * logl(x);
    a[2] = z * y * logl(x);
    a[3] = z * y * logl(x);
    a[4] = powl(x, z) * logl(y);
    a[5] = powl(z, x) * logl(y);
    a[6] = z * x * logl(y);
    a[7] = z * x * logl(y);
    a[8] = powl(x, y) * logl(z);
    a[9] = powl(y, z) * logl(z);
    a[10] = x * y * logl(z);
    a[11] = x * y * logl(z);
    long double mx = -1e20;
    int idx = 0;
    for (int i = 0; i < 12; i++) {
      if (mx < a[i]) mx = a[i], idx = i;
    }
    puts(s[idx]);
  }
}
