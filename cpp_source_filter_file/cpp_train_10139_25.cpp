#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    if (i <= n % m)
      cout << n / m << " ";
    else
      cout << n / m + 1 << " ";
  }
}
