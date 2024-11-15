#include <bits/stdc++.h>
typedef struct {
  long long t[100][100];
} matrices;
long long C[50][50];
long long MOD = 1000000007;
void combin() {
  C[0][0] = 1;
  for (int n = 1; n <= 45; n++) {
    C[0][n] = 1;
    C[n][n] = 1;
    for (int k = 1; k < n; k++) {
      C[k][n] = (C[k][n - 1] + C[k - 1][n - 1]) % MOD;
    }
  }
}
long long n;
int k;
matrices muti(matrices A, matrices B, int l) {
  matrices C;
  memset(C.t, 0, sizeof C.t);
  for (int i = 1; i <= l; i++)
    for (int j = 1; j <= 2 * k + 3; j++)
      for (int z = 1; z <= 2 * k + 3; z++)
        C.t[i][j] = (C.t[i][j] + A.t[i][z] * B.t[z][j]) % MOD;
  return C;
}
void prepare() {
  matrices A;
  matrices B;
  memset(A.t, 0, sizeof A.t);
  memset(B.t, 0, sizeof B.t);
  for (int i = 1; i <= k + 1; i++) A.t[1][i] = 1;
  for (int i = k + 2; i <= 2 * k + 2; i++) A.t[1][i] = 1;
  for (int c = 1; c <= k + 1; c++)
    for (int r = k + 2; r <= k + 2 + c; r++) B.t[r][c] = C[r - k - 2][c - 1];
  for (int c = k + 2; c <= 2 * k + 2; c++)
    for (int r = 1; r <= c - (k + 1); r++) B.t[r][c] = C[r - 1][c - (k + 2)];
  for (int c = k + 2; c <= 2 * k + 2; c++)
    for (int r = k + 2; r <= c; r++) B.t[r][c] = C[r - k - 2][c - k - 2];
  B.t[2 * k + 2][2 * k + 3] = 1;
  B.t[2 * k + 3][2 * k + 3] = 1;
  while (n > 0) {
    if (n % 2) A = muti(A, B, 1);
    B = muti(B, B, 2 * k + 3);
    n /= 2;
  }
  printf("%I64d", A.t[1][2 * k + 3]);
}
int main() {
  scanf("%I64d %d", &n, &k);
  combin();
  prepare();
}
