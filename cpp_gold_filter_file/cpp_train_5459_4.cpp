#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << (n * n) / 4 << endl;
  for (int i = 1; i <= n / 2; i++) {
    for (int j = (n / 2) + 1; j <= n; j++) {
      cout << i << ' ' << j << endl;
    }
  }
}
