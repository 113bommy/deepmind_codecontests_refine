#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x;
  cin >> x;
  if (x <= 127)
    cout << "byte" << endl;
  else if (x <= 32767)
    cout << "short" << endl;
  else if (x <= 2147483647)
    cout << "int" << endl;
  else if (x <= 9223372036854775807)
    cout << "long" << endl;
  else
    cout << "BigInteger" << endl;
}
