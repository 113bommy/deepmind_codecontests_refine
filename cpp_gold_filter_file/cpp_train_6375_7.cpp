#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, ff, A, B, a[N], b[N], vis[N], x[N], y[N], f[40005];
inline void sol(int o, int ff = 0) {
  printf("+ %d\n", o);
  fflush(stdout);
  int a1, b1;
  scanf("%d%d", &a1, &b1);
  int sa = a1 - A;
  int sb = b1 - B - y[o - 1] * y[o - 2];
  if (!ff) {
    if (sb) vis[o + 1] = 1;
  } else
    vis[o + 1] = b1 - B;
  x[o] = sa ? f[sa] : vis[o];
  y[o] = x[o] + 1;
  if (!ff) {
    if (o == n - 1) x[o + 1] = sb / y[o - 1];
  }
  A = a1;
  B = b1;
}
void init() {
  printf("+ %d\n", 1);
  fflush(stdout);
  int a1, b1;
  scanf("%d%d", &a1, &b1);
  int x2x3 = b1 - B;
  if (a1 == A) {
    printf("+ %d\n", 2);
    fflush(stdout);
    int a2, b2;
    scanf("%d%d", &a2, &b2);
    if (a2 == a1) {
      int a0 = A, b0 = B;
      int sb = b2 - b1;
      if (sb) vis[3] = 1;
      A = a2;
      B = b2;
      sol(3, 1);
      printf("+ %d\n", 1);
      fflush(stdout);
      int a3, b3;
      scanf("%d%d", &a3, &b3);
      x[1] = f[a3 - A] - 1;
      y[1] = x[1] + 2;
      y[2] = (b3 - B) / y[3];
      x[2] = y[2] - 1;
      vis[4] = vis[4] - (y[1] - 1) * y[2];
      if (n == 4) x[4] = vis[4] / y[2];
      if (vis[4]) vis[4] = 1;
      A = a3;
      B = b3;
    } else {
      x[2] = f[a2 - a1];
      y[2] = x[2] + 1;
      int sb = b2 - b1;
      if (sb) vis[3] = 1;
      printf("+ %d\n", 1);
      fflush(stdout);
      int a3, b3;
      scanf("%d%d", &a3, &b3);
      x[1] = f[a3 - a2] - 1;
      y[1] = x[1] + 2;
      A = a3;
      B = b3;
      sol(3);
    }
  } else {
    x[1] = f[a1 - A];
    y[1] = x[1] + 1;
    A = a1;
    B = b1;
    printf("+ %d\n", 2);
    fflush(stdout);
    int a2, b2;
    scanf("%d%d", &a2, &b2);
    if (a2 == A) {
      printf("+ %d\n", 2);
      fflush(stdout);
      int a3, b3;
      scanf("%d%d", &a3, &b3);
      x[2] = f[a3 - a2] - 1;
      y[2] = x[2] + 2;
      A = a3;
      B = b3;
      int sb = b3 - b2;
      if (sb) vis[3] = 1;
      sol(3);
    } else {
      x[2] = f[a2 - A];
      y[2] = x[2] + 1;
      A = a2;
      B = b2;
      int sb = b2 - b1;
      if (sb) vis[3] = 1;
      sol(3);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &A, &B);
  for (int i = 1; i <= 200; i++) f[i * (i - 1) / 2] = i;
  init();
  for (register int i = (4); i <= (n - 1); ++i) sol(i);
  printf("! ");
  for (register int i = (1); i <= (n); ++i) printf("%d ", x[i]);
  return 0;
}
