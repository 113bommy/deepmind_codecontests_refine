#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 0;
  cin >> n >> m;
  for (; m > n; m >>= 1) {
    k++;
    if (m % 2 == 0)
      m++;
    else
      m /= 2;
  }
  cout << k + n - m << endl;
}
