#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, sum, mod1, mod, mod2;
  cin >> a >> b >> c;
  sum = (a + b);
  if (a >= b || a <= b && (c <= sum)) {
    if (a == c) {
      cout << "YES" << endl;
    } else if (c == sum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (c > sum) {
    mod = sum % 2;
    sum = sum + 1;
    mod1 = sum % 2;
    mod2 = c % 2;
    if (mod2 == mod1 || mod2 == mod) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
