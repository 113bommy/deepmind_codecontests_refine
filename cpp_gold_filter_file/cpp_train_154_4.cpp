#include <bits/stdc++.h>
using namespace std;
char s[20][10] = {" ",     "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y",
                  "y^x^z", "y^z^x",   "(y^x)^z", "(y^z)^x", "z^x^y",
                  "z^y^x", "(z^x)^y", "(z^y)^x"};
long double a[20];
long double x, y, z;
int main() {
  cin >> x >> y >> z;
  a[1] = pow(y, z) * log(x);
  a[2] = pow(z, y) * log(x);
  a[3] = a[4] = y * z * log(x);
  a[5] = pow(x, z) * log(y);
  a[6] = pow(z, x) * log(y);
  a[7] = a[8] = x * z * log(y);
  a[9] = pow(x, y) * log(z);
  a[10] = pow(y, x) * log(z);
  a[11] = a[12] = y * x * log(z);
  long double ans = a[1];
  int id = 1;
  for (int i = 2; i <= 12; i++)
    if (a[i] > ans) {
      ans = a[i];
      id = i;
    }
  printf("%s\n", s[id]);
  return 0;
}
