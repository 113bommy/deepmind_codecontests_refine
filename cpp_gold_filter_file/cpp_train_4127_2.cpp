#include <bits/stdc++.h>
using namespace std;
int x, y, n, i, j, k, m;
int X[25], Y[25], S[25], D[25][25], M[1 << 24], P[1 << 24], Q[1 << 24];
int main() {
  scanf("%d%d%d", &x, &y, &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &X[i], &Y[i]);
    X[i] -= x;
    Y[i] -= y;
    S[i] = X[i] * X[i] + Y[i] * Y[i];
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      D[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
  for (i = (1 << n) - 2; i >= 0; i--) {
    for (j = 0; i & 1 << j; j++)
      ;
    m = i | 1 << j;
    M[i] = M[m] + S[j] * 2;
    P[i] = j;
    Q[i] = -1;
    for (k = j + 1; k < n; k++)
      if (!(i & 1 << k)) {
        x = M[m | 1 << k] + D[j][k] + S[j] + S[k];
        if (x < M[i]) {
          M[i] = x;
          P[i] = j;
          Q[i] = k;
        }
      }
  }
  printf("%d\n", M[0]);
  for (i = 0; i + 1 != 1 << n;) {
    printf("0 ");
    if (Q[i] == -1) {
      printf("%d ", P[i] + 1);
      i |= 1 << P[i];
    } else {
      printf("%d %d ", P[i] + 1, Q[i] + 1);
      i |= 1 << P[i] | 1 << Q[i];
    }
  }
  printf("0\n");
  return 0;
}
