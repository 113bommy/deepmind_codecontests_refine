#include <bits/stdc++.h>
using namespace std;
int m, n, i, dx, dy, have, s[2][2], x[110000], y[110000], cx[110000],
    cy[110000];
long long ans;
void read(int &x) {
  char k;
  for (k = getchar(); k <= 32; k = getchar())
    ;
  for (x = 0; '0' <= k; k = getchar()) x = x * 10 + k - '0';
}
int main() {
  read(n);
  for (i = 1; i <= n; i++) read(x[i]), read(y[i]), cx[i] = x[i], cy[i] = y[i];
  sort(x + 1, x + n + 1);
  sort(y + 1, y + n + 1);
  m = (n + 1) / 2;
  dx = x[m + 1] - x[m];
  dy = y[m + 1] - y[m];
  if (n % 2 == 1) {
    dx = min(dx, x[m] - x[m - 1]);
    dy = min(dy, y[m] - y[m - 1]);
  }
  for (i = 1; i <= n; i++) {
    ans += abs(x[i] - x[m]) + abs(y[i] - y[m]);
    s[cx[i] <= x[m]][cy[i] <= y[m]] = true;
    if (cx[i] == x[m] && cy[i] == y[m]) have = true;
  }
  if ((n % 2 == 0 || have) && s[0][0] && s[0][1]) ans = max(ans - dx, ans - dy);
  printf("%I64d\n", ans * 2);
}
