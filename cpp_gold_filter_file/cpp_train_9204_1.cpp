#include <bits/stdc++.h>
using namespace std;
int n, m, t, a, b, d[110], c, i, j;
int main() {
  cin >> n;
  while (n--) {
    cin >> m;
    for (j = 0; j < m; j++) {
      cin >> t;
      if (m & 1 && j == m >> 1) {
        d[c++] = t;
        continue;
      }
      if (j < m >> 1)
        a += t;
      else
        b += t;
    }
  }
  sort(d, d + c);
  for (i = c - 1; i >= 0; i--)
    if (1 & n++)
      a += d[i];
    else
      b += d[i];
  cout << a << ' ' << b;
  return 0;
}
