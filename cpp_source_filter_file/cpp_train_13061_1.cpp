#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a = s;
  for (int i = 0; i < n - 1; i++) {
    string p = s.substr(i) + s.substr(0, i);
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < n; k++) {
        p[k]++;
        if (p[k] > '9') p[k] -= 10;
      }
      a = min(a, p);
    }
  }
  cout << a << endl;
  return 0;
}
