#include <bits/stdc++.h>
char s1[2000];
int a[2000][2000] = {0};
int sum[1000][1000] = {0};
int full[1000][1000] = {0};
int n, m, k;
int rec(int i, int j, int &t, int &l, int &s) {
  if (a[i][j] == 1) {
    s++;
    if (i > t) t = i;
    if (j > l) l = j;
    a[i][j] = 0;
    if (i > 0) rec(i - 1, j, t, l, s);
    if (j > 0) rec(i - 1, j, t, l, s);
    if (i < n - 1) rec(i + 1, j, t, l, s);
    if (j < m - 1) rec(i, j + 1, t, l, s);
  }
}
struct Rect {
  int i1, j1, i2, j2;
};
struct otr {
  int l;
  int r;
  int n;
};
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
otr b[100];
Rect r[100];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", s1);
    for (int j = 0; j < m; j++) a[i][j] = (s1[j] == '*') ? 1 : 0;
  }
  int rn = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        int i1 = i;
        r[rn].i1 = i;
        r[rn].j1 = j;
        while (a[i1][j]) {
          for (int j1 = j; a[i1][j1]; j1++) {
            a[i1][j1] = 0;
            r[rn].i2 = i1;
            r[rn].j2 = j1;
          }
          i1++;
        }
        rn++;
      }
    }
  for (int i = 0; i < rn; i++)
    for (int j = i + 1; j < rn; j++)
      if (r[i].j1 > r[j].j1) {
        Rect t = r[i];
        r[i] = r[j];
        r[j] = t;
      }
  long long ans = 0;
  for (int i1 = 0; i1 < n; i1++)
    for (int i2 = i1; i2 < n; i2++) {
      int bn = 0;
      for (int k = 0; k < rn; k++) {
        if (r[k].i1 >= i1 && r[k].i2 <= i2) {
          int q = 1;
          if (bn > 0) {
            if (b[bn - 1].r >= r[k].j1) {
              b[bn - 1].n++;
              b[bn - 1].r = max(b[bn - 1].r, r[k].j2);
              continue;
            }
          }
          b[bn].l = r[k].j1;
          b[bn].r = r[k].j2;
          b[bn].n = q;
          bn++;
        } else if (r[k].i2 >= i1 && r[k].i1 <= i1 ||
                   r[k].i2 >= i2 && r[k].i1 <= i2) {
          int q = 5;
          if (bn > 0) {
            if (b[bn - 1].r >= r[k].j1) {
              b[bn - 1].n += 5;
              b[bn - 1].r = max(b[bn - 1].r, r[k].j2);
              continue;
            }
          }
          b[bn].l = r[k].j1;
          b[bn].r = r[k].j2;
          b[bn].n = q;
          bn++;
        }
      }
      int i3 = 0;
      int i4 = 0;
      int sum = b[0].n;
      while (i3 < bn) {
        if (sum > 0 && sum < 4 && i3 != bn) {
          ans += (b[i3].l - ((i3 == 0) ? 0 : b[i3 - 1].r + 1) + 1) *
                 ((i4 < bn - 1 ? b[i4 + 1].l : m) - b[i4].r);
          if (i4 < bn - 1)
            i4++, sum += b[i4].n;
          else
            i3++, i4 = i3, sum = b[i3].n;
        }
        if (sum > 3) i3++, i4 = i3, sum = b[i3].n;
        if (sum < 1) i4++, sum += b[i4].n;
      }
      int re = 4;
    }
  printf("%lld", ans);
}
