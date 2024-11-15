#include <bits/stdc++.h>
using namespace std;
const int N = 4444;
const int BASE = 1e9 + 7;
int n, c[N][N], f[N][2];
void add(int &x, int y) {
  x += y;
  if (x >= BASE) x -= BASE;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j > i)
        c[i][j] = 0;
      else if ((j == i) || (j == 0))
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % BASE;
    }
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int flag = 0; flag < 2; flag++) {
      if (f[i][flag] == 0) continue;
      for (int j = 2; i + j <= n; j++) {
        int cur = (f[i][flag] * 1LL * c[n - i - 1][j - 1]) % BASE;
        add(f[i + j][flag], cur);
      }
      add(f[i + 1][1], f[i][flag]);
      add(f[i + 1][flag], f[i][flag]);
    }
  }
  printf("%d\n", f[n][1]);
}
