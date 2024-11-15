#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 0x3fffffff;
template <typename T>
void read(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; (c ^ 48) > 9; c = getchar())
    if (c == '-') neg = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
int n, m, a[N], v[N], c[N][2], f[N][2];
void add(int k, int x, int y) {
  for (++x; x <= m; x += (x & -x)) c[x][k] = min(c[x][k], y);
}
int getmin(int k, int x) {
  int ans = INF;
  for (++x; x; x -= (x & -x)) ans = min(ans, c[x][k]);
  return ans;
}
int main() {
  read(n);
  if (n == 1 || n == 2) return puts("0"), 0;
  for (int i = 0, i_end = n; i < i_end; ++i) read(a[i]), v[i] = (a[i] -= i);
  for (int i = 0, i_end = n; i < i_end; ++i) v[i + n] = v[i] - 1;
  m = (n + 1) * 2;
  v[m - 2] = -INF;
  v[m - 1] = -INF - 1;
  sort(v, v + m);
  m = unique(v, v + m) - v;
  for (int i = 0, i_end = n; i < i_end; ++i)
    a[i] = lower_bound(v, v + m, a[i]) - v;
  for (int i = 1, i_end = m + 1; i < i_end; ++i) c[i][0] = c[i][1] = INF;
  add(0, 1, 0);
  add(1, 1, 0);
  for (int i = 0, i_end = n; i < i_end; ++i) {
    f[i + 1][0] = getmin(0, a[i]) + i;
    f[i + 1][1] = min(getmin(1, a[i]) + i, max(f[i + 1][0] - 1, 0));
    add(0, a[i], f[i + 1][0] - i - 1);
    add(1, a[i], f[i + 1][1] - i - 1);
    if (i) add(1, a[i - 1] - 1, f[i][0] - i - 1);
  }
  printf("%d\n", min(getmin(1, m - 1) + n, f[n][0]));
  return 0;
}
