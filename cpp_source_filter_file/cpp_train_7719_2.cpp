#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, r, i, j;
  cin >> n >> m;
  if (m == 0) {
    cout << 1;
  } else {
    if (m < n / 2) {
      cout << m;
    } else {
      cout << n - m;
    }
  }
  return 0;
}
