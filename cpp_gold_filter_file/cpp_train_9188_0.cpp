#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, q;
  cin >> n;
  long long a[n + 1], i, temp = 1;
  for (i = 2; i <= n; i++) {
    cout << "? " << temp << " " << i << "\n";
    cin >> p;
    cout << "? " << i << " " << temp << "\n";
    cin >> q;
    if (p > q) {
      a[temp] = p;
      temp = i;
    } else {
      a[i] = q;
    }
  }
  a[temp] = n;
  cout << "! ";
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  cout << "\n";
  return 0;
}
