#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  string b;
  cin >> a >> b >> b;
  if (b == "week")
    if (a == 5 || a == 6)
      cout << 53 << endl;
    else
      cout << 52 << endl;
  else if (a <= 29)
    cout << 12 << endl;
  else if (a == 30)
    cout << 11 << endl;
  else if (a == 31)
    cout << 7 << endl;
  return 0;
}
