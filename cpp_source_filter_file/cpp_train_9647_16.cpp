#include <bits/stdc++.h>
const int maxd = 2000000 + 300;
struct task {
  int x, y;
  void prin1() { printf("%d %d\n", x, y); }
} a[maxd];
int c[25];
int nn, n, l, last, x;
inline void pout(int x, int y) {
  a[++l].x = x;
  a[l].y = y;
}
void work1(int i, int x, int y, int z) {
  if (i == n + 1) return;
  work1(i + 1, x, z, y);
  for (int j = 1; j <= c[i]; j++) pout(x, y);
  work1(i + 1, z, y, x);
}
void work2(int i, int x, int y, int z) {
  if (i == n) {
    for (int i = 1; i < c[1]; i++) pout(x, z);
    pout(x, y);
    for (int i = 1; i < c[1]; i++) pout(z, y);
    return;
  }
  if (c[i] > 1) {
    work1(i + 1, x, y, z);
    for (int j = 1; j <= c[i]; j++) pout(x, z);
    work1(i + 1, y, x, z);
    for (int j = 1; j <= c[i]; j++) pout(z, y);
    work2(i + 1, x, y, z);
  } else
    work1(i, x, y, z);
}
int main() {
  scanf("%d", &nn);
  n = 0;
  last = 0x7fffffff;
  for (int i = 1; i <= nn; i++) {
    scanf("%d", &x);
    if (x != last)
      c[++n] = 1, last = x;
    else
      c[n]++;
  }
  l = 0;
  work2(1, 1, 3, 2);
  printf("%d\n", l);
  for (int i = 1; i <= l; i++) a[i].prin1();
  return 0;
}
