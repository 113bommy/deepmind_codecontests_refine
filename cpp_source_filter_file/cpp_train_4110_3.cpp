#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = max(3 * a / 10, a - a / 250 * c);
  int y = max(3 * b / 10, b - b / 250 * d);
  if (a > b)
    cout << "Misha";
  else if (b > a)
    cout << "Vasya";
  else if (a == b)
    cout << "Tie";
  return 0;
}
