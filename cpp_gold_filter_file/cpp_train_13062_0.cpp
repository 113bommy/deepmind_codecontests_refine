#include <bits/stdc++.h>
using namespace std;
const int N = 701;
int n, m;
struct matrix {
  long long mat[N][N];
  matrix() { memset(mat, 0, sizeof mat); }
  matrix operator*(matrix &a) {
    matrix b;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) b.mat[i][j] += mat[i][k] * a.mat[k][j];
    return b;
  }
  void print() {
    for (int i = 0; i < n; i++, puts(""))
      for (int j = 0; j < n; j++) cout << mat[i][j] << " ";
  }
} base, two, three, five;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d%d", &a, &b);
    base.mat[--a][--b] = 1;
    base.mat[b][a] = 1;
  }
  two = base * base;
  three = two * base;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      five.mat[i][i] += two.mat[i][j] * three.mat[j][i];
  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += five.mat[i][i] - 5 * (two.mat[i][i] - 1) * three.mat[i][i];
  printf("%lld\n", ans / 10);
}
