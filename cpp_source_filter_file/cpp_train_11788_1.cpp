#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s, e, i, cont = 0, len;
    char a[1000];
    cin >> a;
    len = strlen(a);
    for (i = 0; i < len; i++) {
      if (a[i] == '1') {
        s = i;
        break;
      }
    }
    for (i = len - 1; i >= 0; i--) {
      if (a[i] == '1') {
        e = i;
        break;
      }
    }
    for (i = s + 1; i < e; i++) {
      if (a[i] == '0') {
        cont++;
      }
    }
    cout << cont << endl;
  }
}
