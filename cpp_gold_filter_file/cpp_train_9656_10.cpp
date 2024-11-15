#include <bits/stdc++.h>
const int N = 21;
int n, m, ns, a[N], nn[N], b[N], save[1 << N][2];
void makemove(int t, int l, int r) {
  for (; t; t--) save[++ns][0] = l, save[ns][1] = r;
}
int mov(int t, int l, int r) {
  int mid, res = 0;
  for (mid = 1; mid == l || mid == r; ++mid)
    ;
  if (t == m) {
    makemove(nn[t], l, r);
    return nn[t];
  }
  res += mov(t + 1, l, mid);
  makemove(nn[t], l, r);
  res += mov(t + 1, mid, r);
  return res + nn[t];
}
int move(int t, int l, int r) {
  int mid, res = 0;
  for (mid = 1; mid == l || mid == r; ++mid)
    ;
  if (t == m) {
    makemove(nn[t] - 1, l, mid);
    makemove(1, l, r);
    makemove(nn[t] - 1, mid, r);
    return nn[t] * 2 - 1;
  }
  if (b[t])
    return mov(t, l, r);
  else {
    res += mov(t + 1, l, r);
    makemove(nn[t], l, mid);
    res += mov(t + 1, r, l);
    makemove(nn[t], mid, r);
    res += move(t + 1, l, r);
    return res + nn[t] * 2;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, last = 0; i <= n; i++, last = x) {
    scanf("%d", &x);
    if (x != last)
      a[++m] = x, nn[m] = 1;
    else
      ++nn[m];
  }
  for (int i = 1, sa = 0; i <= m; i++) {
    if (nn[i] == 1) sa = i;
    b[i] = sa;
  }
  printf("%d\n", move(1, 1, 3));
  for (int i = 1; i <= ns; i++) printf("%d %d\n", save[i][0], save[i][1]);
}
