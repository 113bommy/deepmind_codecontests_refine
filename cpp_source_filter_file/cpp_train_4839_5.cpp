#include <bits/stdc++.h>
const int N = 2048;
int l[N][N], r[N][N], d[N][N], up[N][N];
char field[N][N];
long long go(int n, int m) {
  long long ans = 0;
  for (int i = 2; i < n; i++)
    if (r[i][1] == m) {
      ans++;
    }
  for (int j = 2; j < m; j++)
    if (d[1][j] == n) {
      ans++;
    }
  for (int i = 2; i < n; i++) {
    for (int j = 2; j <= std::min(m - 1, r[i][1]); j++) {
      if (up[i][j] == i) ans++;
      if (d[i][j] == n - i + 1) ans++;
    }
    for (int j = m - 1; j >= std::max(2, m - l[i][m] + 1); j--) {
      if (up[i][j] == i) ans++;
      if (d[i][j] == n - i + 1) ans++;
    }
  }
  for (int j = 2; j < m; j++) {
    int countl = 0, countr = 0;
    for (int i = 2; i < n; i++) {
      if (field[i][j] != '.') {
        countl = countr = 0;
      }
      if (l[i][j] == j) ans += countr;
      if (r[i][j] == m - j + 1) ans += countl;
      if (l[i][j] == j) countl++;
      if (r[i][j] == m - j + 1) countr++;
    }
  }
  for (int i = 2; i < n; i++) {
    int countu = 0, countd = 0;
    for (int j = 2; j < m; j++) {
      if (field[i][j] != '.') {
        countu = countd = 0;
      }
      if (up[i][j] == i) ans += countd;
      if (d[i][j] == n - i + 1) ans += countu;
      if (up[i][j] == i) countu++;
      if (d[i][j] == n - i + 1) countd++;
    }
  }
  for (int j = 2; j < m; j++) {
    int countl = 0, countr = 0;
    for (int i = 2; i < n; i++) {
      if (field[i][j] != '.') {
        countl = countr = 0;
      }
      if (l[i][j] == j) ans += countr;
      if (r[i][j] == m - j + 1) ans += countl;
      if (field[i][j] != '.') continue;
      if (i > 2 && l[i - 1][j] == j) countl++;
      if (i > 2 && r[i - 1][j] == m - j + 1) countr++;
    }
  }
  for (int i = 2; i < n; i++) {
    int countu = 0, countd = 0;
    for (int j = 2; j < m; j++) {
      if (field[i][j] != '.') {
        countu = countd = 0;
      }
      if (up[i][j] == i) ans += countd;
      if (d[i][j] == n - i + 1) ans += countu;
      if (field[i][j] != '.') continue;
      if (j > 2 && up[i][j - 1] == i) countu++;
      if (j > 2 && d[i][j - 1] == n - i + 1) countd++;
    }
  }
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", field[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (field[i][j] == '.') {
        l[i][j] = l[i][j - 1] + 1;
        up[i][j] = up[i - 1][j] + 1;
      }
    }
    for (int j = m; j > 0; j--) {
      if (field[i][j] == '.') r[i][j] = r[i][j + 1] + 1;
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= m; j++)
      if (field[i][j] == '.') {
        d[i][j] = d[i + 1][j] + 1;
      }
  }
  printf("%I64d\n", go(n, m));
  return 0;
}
