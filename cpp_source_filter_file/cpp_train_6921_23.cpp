#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, c = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] > sum) {
      sum += a[i];
      c++;
    }
  }
  cout << c;
  return 0;
}
