#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[100];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i <= n - 1; i++) {
    cout << a[i];
  }
  return 0;
}
