#include <bits/stdc++.h>
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;
int m[55][55], rec[55][55][5], tx[1001], ty[1001];
int main() {
  int n, b, q;
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2)
      for (int j = min(y1, y2); j <= max(y1, y2); j++) m[x1][j] = 3 + (y1 < y2);
    else
      for (int j = min(x1, x2); j <= max(x1, x2); j++) m[j][y1] = 1 + (x1 < x2);
  }
  cin >> q;
  while (q--) {
    int x, y, z;
    long long t;
    char c;
    scanf("%d%d %c%I64d", &x, &y, &c, &t);
    if (c == 'L')
      z = 1;
    else if (c == 'R')
      z = 2;
    else if (c == 'D')
      z = 3;
    else
      z = 4;
    for (int i = 0; i <= b; i++)
      for (int j = 0; j <= b; j++)
        for (int z = 1; z <= 4; z++) rec[i][j][z] = -1;
    for (int i = 0; i < t; i++)
      if (rec[x][y][z] != -1) {
        printf("%d %d\n", tx[(t - i) % (i - rec[x][y][z]) + rec[x][y][z]],
               ty[(t - i) % (i - rec[x][y][z]) + rec[x][y][z]]);
        goto out;
      } else {
        rec[x][y][z] = i;
        tx[i] = x;
        ty[i] = y;
        if (m[x][y]) z = m[x][y];
        if (z == 1)
          x = max(x - 1, 0);
        else if (z == 2)
          x = min(x + 1, b);
        else if (z == 3)
          y = max(y - 1, 0);
        else
          y = min(y + 1, b);
      }
    printf("%d %d\n", x, y);
  out:;
  }
  return 0;
}
