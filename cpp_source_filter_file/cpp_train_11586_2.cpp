#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int a[105], z;
bool check(int k) {
  int b[50], i, j;
  memset(b, 0, sizeof(b));
  for (i = 0; i < z; i++) {
    for (j = 0; a[i] > 0; j++) {
      b[j] += a[i] % 2;
      a[i] /= 2;
    }
  }
  for (i = 0; i < 50; i++) {
    if (b[i] % (k + 1) != 0) return 1;
  }
  return 0;
}
int main() {
  int n, m, k, i, j, t, x, y;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> s[i];
  t = 0;
  z = 0;
  for (i = 0; i < n; i++) {
    x = 0;
    for (j = 0; j < m; j++)
      if (s[i][j] == '-') x++;
    if (x == 0 || x == m) continue;
    x = y = -1;
    for (j = 0; j < m; j++) {
      if (s[i][j] == 'R')
        x = j;
      else if (s[i][j] == 'G')
        y = j;
    }
    if (x != -1 && y == -1)
      t |= 1;
    else if (x == -1 && y != -1)
      t |= 2;
    else {
      if (x < y)
        a[z] = y - x - 1;
      else
        a[z] = x - y - 1;
      z++;
    }
  }
  if (t == 3)
    cout << "Draw" << endl;
  else if (t == 1)
    cout << "First" << endl;
  else if (t == 2)
    cout << "Second" << endl;
  else {
    if (check(k))
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
