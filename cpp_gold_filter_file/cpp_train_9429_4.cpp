#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = n - 1; i >= 2; i--)
    if (a[i] < a[i - 1] + a[i - 2]) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
  return 0;
}
