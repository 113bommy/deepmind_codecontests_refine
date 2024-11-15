#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
const int N = 55;
int n;
double p, q, dp[N][N], A[N][N], B[N][N];
struct matrix {
  double a[N][N];
  inline double* operator[](int x) { return a[x]; }
} zs, ans;
const double eps = 1e-10;
matrix operator*(matrix a, matrix b) {
  matrix c;
  memset(c.a, 0, sizeof(c.a));
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++)
      if (fabs(a[i][j]) < eps) {
        for (int k = 0; k <= 50; k++) {
          c[i][k] += a[i][j] * b[j][k];
        }
      }
  }
  return c;
}
matrix ksm(matrix ans, matrix zs, int k) {
  for (; k; k >>= 1) {
    if (k & 1) ans = ans * zs;
    zs = zs * zs;
  }
  return ans;
}
int main() {
  n = read();
  p = (double)read() / 1000000000;
  q = 1 - p;
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 50; j++) {
      A[i][j] = A[i][j - 1] * A[i - 1][j - 1];
      B[i][j] = B[i][j - 1] * A[i - 1][j - 1];
      if (j == 1)
        A[i][j] += p;
      else if (j == 2) {
        A[i][j] += q;
        B[i][j] += q;
      }
    }
  }
  for (int i = 50; i; i--) {
    for (int j = 1; j <= 50; j++) {
      A[i][j] *= (1 - A[i - 1][j]);
      B[i][j] *= (1 - A[i - 1][j]);
    }
  }
  dp[1][1] = 1;
  dp[1][2] = 2;
  for (int i = 2; i <= 50; i++) {
    for (int j = 1; j <= 50; j++) {
      double sum = 0;
      if (j == 1) {
        for (int k = 2; k <= 50; k++) {
          dp[i][j] += dp[i - 1][k] * B[i - 1][k];
          sum += B[i - 1][k];
        }
      } else {
        for (int k = 1; k < j; k++) {
          dp[i][j] += dp[i - 1][k] * A[i - 1][k];
          sum += A[i - 1][k];
        }
      }
      dp[i][j] /= sum;
      dp[i][j] += j;
    }
  }
  if (n < 50) {
    printf("%.10lf\n", (double)(dp[n + 1][50] - 50));
    return 0;
  }
  for (int i = 1; i <= 50; i++) {
    if (i == 1) {
      double sum = 0;
      for (int j = 2; j <= 50; j++) sum += B[50][j];
      for (int j = 2; j <= 50; j++) zs[j][i] = B[50][j] / sum;
    } else {
      double sum = 0;
      for (int j = 1; j < i; j++) sum += A[50][j];
      for (int j = 1; j < i; j++) zs[j][i] = A[50][j] / sum;
    }
    zs[0][i] = i;
  }
  zs[0][0] = 1;
  for (int i = 1; i <= 50; i++) ans[0][i] = dp[50][i];
  ans[0][0] = 1;
  printf("%.10lf\n", (double)(ksm(ans, zs, n + 1 - 50)[0][50] - 50));
}
