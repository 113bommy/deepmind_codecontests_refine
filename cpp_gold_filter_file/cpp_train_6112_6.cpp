#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  int a[n], b[m];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) cout << a[i] << " ";
    }
  }
  return 0;
}
