#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e;
  for (int i = 0; i <= e; i++) {
    if (i % b == 0 or i % c == 0 or i % d == 0 or i % a == 0) {
      f++;
    }
  }
  cout << f - 1;
}
