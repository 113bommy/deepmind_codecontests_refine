#include <bits/stdc++.h>
using namespace std;
long double a[13];
int main() {
  double xx, yy, zz;
  cin >> xx >> yy >> zz;
  long double x, y, z;
  x = xx;
  y = yy;
  z = zz;
  a[1] = log(x) * pow(y, z);
  a[2] = log(x) * pow(z, y);
  a[3] = log(x) * y * z;
  a[4] = a[3];
  a[5] = log(y) * pow(x, z);
  a[6] = log(y) * pow(z, x);
  a[7] = log(y) * x * z;
  a[8] = a[7];
  a[9] = log(z) * pow(x, y);
  a[10] = log(z) * pow(y, x);
  a[11] = log(z) * x * y;
  a[12] = a[11];
  int j;
  long double mina;
  mina = 0;
  for (int i = 1; i <= 12; i++) {
    if (a[i] > mina) {
      j = i;
      mina = a[i];
    }
  }
  if (j == 1) {
    cout << "x^y^z" << endl;
  }
  if (j == 2) {
    cout << "x^z^y" << endl;
  }
  if (j == 3 || j == 4) {
    cout << "(x^y)^z" << endl;
  }
  if (j == 5) {
    cout << "y^x^z" << endl;
  }
  if (j == 6) {
    cout << "y^z^x" << endl;
  }
  if (j == 7 || j == 8) {
    cout << "(y^x)^z" << endl;
  }
  if (j == 9) {
    cout << "z^x^y" << endl;
  }
  if (j == 10) {
    cout << "z^y^x" << endl;
  }
  if (j == 11 || j == 12) {
    cout << "(z^x)^y" << endl;
  }
  return 0;
}
