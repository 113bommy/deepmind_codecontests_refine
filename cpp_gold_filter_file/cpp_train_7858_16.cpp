#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 1, m = 1;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] <= a[i + 1]) {
      k++;
    } else if (a[i] > a[i + 1]) {
      k = 1;
    }
    if (k > m) {
      m = k;
    }
  }
  cout << m;
}
