#include <bits/stdc++.h>
using namespace std;
const int maxn = 500003;
int n, a[maxn], f[20][maxn], g[20][maxn], Log[maxn];
long long ans = 0;
int get() {
  int f = 0, v = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') break;
  if (ch == '-')
    f = 1;
  else
    v = ch - 48;
  while (isdigit(ch = getchar())) v = v * 10 + ch - 48;
  if (f == 1)
    return -v;
  else
    return v;
}
int main() {
  n = get();
  Log[0] = -1;
  for (int i = 1; i <= n; i++) a[i] = a[i + n] = -get();
  for (int i = 1; i <= 2 * n; i++)
    a[i] += i, f[0][i] = i, Log[i] = Log[i / 2] + 1;
  f[0][2 * n] = 0;
  a[2 * n] = n * 2;
  for (int i = 1; i <= Log[2 * n]; i++)
    for (int j = 1; j + (1 << i) <= 2 * n; j++) {
      int x = f[i - 1][j], y = f[i - 1][j + (1 << i - 1)];
      if (a[x] < a[y])
        f[i][j] = x;
      else
        f[i][j] = y;
    }
  for (int i = 1; i < 2 * n; i++) {
    if (a[i] <= 0) {
      g[0][i] = 0;
      continue;
    }
    int x = a[i], y = i - 1, tp = Log[y - x + 1];
    x = f[tp][x], y = f[tp][y - (1 << tp) + 1];
    if (a[x] < a[y])
      g[0][i] = x;
    else
      g[0][i] = y;
  }
  for (int i = 1; i <= Log[2 * n]; i++)
    for (int j = 1; j < 2 * n; j++) f[i][j] = f[i - 1][f[i - 1][j]];
  for (int i = n; i < 2 * n; i++) {
    ans += 1 + (a[i] > i - n + 1);
    for (int x = i, j = Log[2 * n]; j >= 0; j--)
      if (a[g[j][x]] > i - n + 1) x = g[j][x], ans += 1 << j;
  }
  cout << ans << endl;
  return 0;
}
