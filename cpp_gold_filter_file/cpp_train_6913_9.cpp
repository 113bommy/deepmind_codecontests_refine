#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, k, i;
  cin >> d >> k;
  if (k == 0 && d > 1) {
    cout << "No solution" << endl;
  } else {
    cout << k;
    for (i = 1; i < d; i++) cout << 0;
  }
  return 0;
}
