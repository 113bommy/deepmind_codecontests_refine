#include <bits/stdc++.h>
using namespace std;
int n, N, F[21][2], R[21], x, i, j, A[21], P[21];
void Prt(int K, int S, int T, int C) {
  if (C == N + 1) return;
  if (K == 0) {
    if (A[C] == 1) {
      Prt(1, S, 6 - S - T, C + 1);
      for (i = 1; i <= A[C]; i++) printf("%d %d\n", S, T);
      Prt(1, 6 - S - T, T, C + 1);
      return;
    }
    if (P[C] == 0) {
      Prt(1, S, T, C + 1);
      for (i = 1; i < A[C]; i++) printf("%d %d\n", S, 6 - S - T);
      Prt(1, T, 6 - S - T, C + 1);
      printf("%d %d\n", S, T);
      Prt(1, 6 - S - T, S, C + 1);
      for (i = 1; i < A[C]; i++) printf("%d %d\n", 6 - S - T, T);
      Prt(1, S, T, C + 1);
    }
    if (P[C] == 1) {
      Prt(1, S, T, C + 1);
      for (i = 1; i < A[C]; i++) printf("%d %d\n", S, 6 - S - T);
      Prt(1, T, S, C + 1);
      for (i = 1; i < A[C]; i++) printf("%d %d\n", 6 - S - T, T);
      Prt(0, S, T, C + 1);
    }
  }
  if (K == 1) {
    Prt(1, S, 6 - S - T, C + 1);
    for (i = 1; i <= A[C]; i++) printf("%d %d\n", S, T);
    Prt(1, 6 - S - T, T, C + 1);
  }
}
void Dp() {
  F[N][0] = 2 * A[N] - 1;
  F[N][1] = A[N];
  for (i = N - 1; i > 0; i--) {
    F[i][1] = F[i + 1][1] * 2 + A[i];
    if (A[i] == 1) {
      F[i][0] = 1 + F[i + 1][1] * 2;
      continue;
    }
    if ((F[i + 1][1] * 2 + A[i] - 1) * 2 + 1 <
        F[i + 1][0] + A[i] * 2 + F[i + 1][1] * 2)
      F[i][0] = (F[i + 1][1] * 2 + A[i] - 1) * 2 + 1, P[i] = 0;
    else
      F[i][0] = F[i + 1][0] + A[i] * 2 + F[i + 1][1] * 2, P[i] = 1;
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (R[N] != x) R[++N] = x;
    A[N]++;
  }
  Dp();
  printf("%d\n", F[1][0]);
  Prt(0, 1, 3, 1);
  return 0;
}
