#include <bits/stdc++.h>
using namespace std;
int a[3];
int main() {
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if ((a[0] % 2) == (a[1] % 2))
    cout << a[1] << "\n";
  else
    cout << a[2] << "\n";
  return 0;
}
