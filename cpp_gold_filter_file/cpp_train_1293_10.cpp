#include <bits/stdc++.h>
using namespace std;
const int n = 95;
int k, a[n + 6][n + 6];
inline void e(int u, int v) { a[u][v] = a[v][u] = true; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> k;
  cout << n << '\n';
  e(0, 2), e(0, 3);
  for (int i = 2, cnt = 0; cnt < 31; cnt++, i += 3) {
    e(i, i + 3), e(i, i + 4);
    e(i + 1, i + 3), e(i + 1, i + 4);
    e(i + 2, i + 5);
    if (k & 1 << cnt) e(i + 1, i + 2);
  }
  e(94, 1);
  for (int i = 0; i < n; i++, cout << '\n')
    for (int j = 0; j < n; j++) cout << (a[i][j] ? 'Y' : 'N');
  return 0;
}
