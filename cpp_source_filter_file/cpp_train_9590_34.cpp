#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  for (i = n; i > 0; i--) {
    if (n % i != 0) {
      cout << n - i;
      return 0;
    }
  }
  cout << 1;
  return 0;
}
