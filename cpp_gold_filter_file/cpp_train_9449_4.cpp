#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
}

