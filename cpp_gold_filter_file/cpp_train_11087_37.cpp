#include <bits/stdc++.h>
using namespace std;
int n, i, m;
int b[100001];
int a[100001];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  m = a[n - 1];
  for (i = n - 2; i >= 0; i--) {
    if (m >= a[i]) b[i] = m - a[i] + 1;
    if (m < a[i]) m = a[i];
  }
  for (i = 0; i < n; i++) cout << b[i] << ' ';
}
