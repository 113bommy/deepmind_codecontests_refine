#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a[0] == c[2] && a[1] == c[1] && a[2] == c[2] && b[0] == b[2]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
