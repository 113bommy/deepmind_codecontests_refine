#include <bits/stdc++.h>
using namespace std;
int a, s, d, f, g, h, j, k, l, i, n;
string x;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    s = -1;
    for (a = 0; a < 8; a++) {
      cin >> x;
      for (j = 0; j < 8; j++) {
        if (x[j] == 'K') {
          if (s == -1) {
            s = a;
            d = j;
          } else {
            f = a;
            g = j;
            if ((abs(s - f) == 4 || abs(d - g) == 4) &&
                (abs(s - f) == 0 || abs(d - g) == 0)) {
              cout << "YES" << endl;
              break;
            }
            if ((abs(s - f) == 4 && abs(d - g) == 4)) {
              cout << "YES" << endl;
              break;
            }
            cout << "NO" << endl;
          }
        }
      }
    }
  }
}
