#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, d[120], R, G, br, bg, x, y;
char c[120];
void add(int x) {
  for (int i = 0; i <= 10; ++i) d[i] += x % 2, x /= 2;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  R = G = 0;
  for (i = 1; i <= n; ++i) {
    scanf("%s", c + 1);
    x = y = 0;
    br = bg = 0;
    for (j = 1; j <= m; ++j) {
      bg |= c[j] == 'G';
      br |= c[j] == 'R';
      if (c[j] != '-')
        if (!x)
          x = j;
        else
          y = j;
    }
    if (!y && m > 1)
      R |= br, G |= bg;
    else if (y && (!br || !bg) && m > 2)
      R |= br, G |= bg;
    else if (br && bg)
      add(y - x - 1);
  }
  if (R && G)
    puts("Draw");
  else if (R)
    puts("Second");
  else if (G)
    puts("First");
  else {
    for (i = 0; i <= 10; ++i)
      if (d[i] % (k + 1)) return puts("First"), 0;
    puts("Second");
  }
}
