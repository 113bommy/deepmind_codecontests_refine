#include <bits/stdc++.h>
using namespace std;
long a, m, i, k, t;
int main() {
  cin >> a >> m;
  for (i = 0; i <= 20; i++) {
    t = pow(2, i);
    if (a * t % m == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
