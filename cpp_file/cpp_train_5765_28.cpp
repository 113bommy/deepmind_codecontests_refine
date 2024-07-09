#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long double a[maxn][maxn], x[maxn];
int n, m, r, c;
void printa() {
  cout << "P ST P A " << endl;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m + 1; j++) {
      printf("%.2Lf ", a[i][j]);
    }
    cout << endl;
  }
  cout << "P A DONE " << endl;
}
void printx() {
  cout << "P ST X" << endl;
  for (int i = 1; i <= m; i++) {
    printf("%.2Lf ", x[i]);
  }
  cout << endl;
}
void gao() {
  for (int i = 1; i <= m - 1; i++) {
    long double r = a[i + 1][i] / a[i][i];
    for (int j = i; j <= i + 1; j++) {
      a[i + 1][j] -= r * a[i][j];
    }
    a[i + 1][m + 1] -= r * a[i][m + 1];
  }
  for (int i = m; i - 1 >= 1; i--) {
    long double r = a[i - 1][i] / a[i][i];
    a[i - 1][i] = 0;
    a[i - 1][m + 1] -= a[i][m + 1] * r;
  }
  for (int i = 1; i <= m; i++) {
    x[i] = a[i][m + 1] / a[i][i];
  }
}
int main() {
  cin >> n >> m >> r >> c;
  if (r == n) {
    cout << "0.0000000000" << endl;
    return 0;
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (j == 1) {
        a[1][1] = 2.0 / 3.0;
        a[1][2] = -1.0 / 3.0;
        a[1][m + 1] = 1.0 / 3.0 * x[1] + 1;
        continue;
      } else if (j == m) {
        a[m][m - 1] = -1.0 / 3.0;
        a[m][m] = 2.0 / 3.0;
        a[m][m + 1] = 1.0 / 3.0 * x[m] + 1;
        continue;
      } else {
        a[j][j - 1] = -1.0 / 4.0;
        a[j][j] = 3.0 / 4.0;
        a[j][j + 1] = -1.0 / 4.0;
        a[j][m + 1] = 1.0 / 4 * x[j] + 1;
      }
    }
    if (m == 1) {
      a[1][1] = 1.0 / 2.0;
      a[1][m + 1] = 1.0 / 2.0 * x[1] + 1;
    }
    gao();
    if (i == r) {
      printf("%.6Lf", x[c]);
      return 0;
    }
  }
}
