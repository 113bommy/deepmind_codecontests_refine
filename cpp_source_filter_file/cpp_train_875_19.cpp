#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << min(a, min(b, min(c / 2, min(d / 6, e / 4))));
}
