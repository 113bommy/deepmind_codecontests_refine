#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << (n / 5) * (m / 5) + ((n + 4) / 5) * ((m + 1) / 5) +
              ((n + 3) / 5) * ((m + 2) / 5) + ((n + 2) / 5) * ((m + 3) / 5) +
              ((n + 1) / 5) * ((m + 4) / 5)
       << endl;
  return 0;
}
