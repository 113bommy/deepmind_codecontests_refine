#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  while (n1 > 0 && n2 > 0) {
    n1--;
    n2--;
  }
  if (n2 == 0 && n1 != 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
