#include <bits/stdc++.h>
using namespace std;
int f[5];
int m, k, n;
string a, b;
int main() {
  cin >> n >> a >> b;
  m = a.size();
  k = b.size();
  for (int i = 0; i < n && i < m * k; i++) {
    char p = a[i % m], r = b[i % k];
    if (p != r) {
      int d = (n - i + m * k - 1) / (m * k);
      if ((p == 'R' && r == 'S') || (p == 'S' && r == 'P') ||
          (p == 'P' && r == 'R'))
        f[2] += d;
      else
        f[1] += d;
    }
  }
  cout << f[1] << " " << f[2];
  return 0;
}
