#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, L = 1;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i != 0) {
      if (a[i] > a[L - 1]) L = i + 1;
    }
  }
  if (a[0] > a[L - 1]) L = 1;
  sort(a, a + n);
  cout << L << " " << a[n - 2];
  return 0;
}
