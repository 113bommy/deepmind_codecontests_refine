#include <bits/stdc++.h>
using namespace std;
bool p(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  long long m, n, i, j, k;
  cin >> n;
  if (p(n)) {
    cout << 1 << endl << 3;
  } else {
    cout << 3 << endl << 3 << " ";
    for (i = 3, n -= 3; i < n; i += 2) {
      if (p(i) && p(n - i)) {
        cout << i << " " << n - i << endl;
        return 0;
      }
    }
  }
}
