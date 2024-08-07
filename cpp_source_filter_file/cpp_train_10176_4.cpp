#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
double F[MAXN][MAXN];
int N, M;
void Solve(int n, int m) {
  if (F[n][m] > -1) return;
  if (!n) {
    F[n][m] = 1.0 / (m + 1);
    return;
  }
  if (!m) {
    F[n][m] = 1;
    return;
  }
  Solve(m, n - 1), Solve(m - 1, n);
  double b = (m / (m + 1.0)) * (1 - F[m - 1][n]), k = 1 - b;
  double b1 = m / (m + 1.0) * (1 - F[m - 1][n]) + 1 / (m + 1.0);
  double k1 = 1 - F[m][n - 1] - b1;
  F[n][m] = (b1 - b) / (k - k1) * k + b;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= M; j++) F[i][j] = -1;
  Solve(N, M);
  printf("%.12f %.12f\n", F[N][M], 1 - F[N][M]);
  return 0;
}
