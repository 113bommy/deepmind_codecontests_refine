#include <bits/stdc++.h>
using namespace std;
long long a[110], b[110];
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1)
    a[0] = 1;
  else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else if (n % 2 == 0) {
    for (int i = 0; i < n - 1; i++) a[i] = 1;
    a[n - 1] = (n - 2) / 2;
  } else {
    a[0] = 4;
    for (int i = 1; i < n - 1; i++) a[i] = 1;
    a[n - 1] = (n + 1) / 2;
  }
  if (m == 1)
    b[0] = 1;
  else if (m == 2) {
    b[0] = 3;
    b[1] = 4;
  } else if (m % 2 == 0) {
    for (int i = 0; i < n - 1; i++) b[i] = 1;
    b[n - 1] = (n - 2) / 2;
  } else {
    b[0] = 4;
    for (int i = 1; i < n - 1; i++) b[i] = 1;
    b[n - 1] = (n + 1) / 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i] * b[j] << " ";
    cout << endl;
  }
  return 0;
}
