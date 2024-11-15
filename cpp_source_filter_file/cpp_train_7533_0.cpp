#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, x;
char re[105][105];
bool bad(int z) { return z < 2 && z > -2; }
char gfc(int r, int c) {
  char ch = 'a';
  for (; ch < 'z'; ch++) {
    if (r && (bad(re[r - 1][c] - ch) || bad(re[r - 1][c + 1] - ch))) continue;
    if (c && (bad(re[r][c - 1] - ch) || bad(re[r + 1][c - 1] - ch))) continue;
    break;
  }
  return ch;
}
int main() {
  scanf("%d %d %d %d %d", &n, &m, &a, &b, &x);
  int sr = 0, sc = 0;
  if (n * m % 2 || a * 2 + b * 2 + x * 4 < n * m) goto IMP;
  if (n % 2) {
    if (b * 2 < m) goto IMP;
    b -= m / 2;
    for (int c = 0; c < m; c += 2)
      re[0][c] = re[0][c + 1] = (c % 4 ? 'y' : 'z');
    sr = 1;
  }
  if (m % 2) {
    if (a * 2 < n) goto IMP;
    a -= n / 2;
    for (int r = 0; r < n; r += 2)
      re[r][0] = re[r + 1][0] = (r % 4 ? 'y' : 'z');
    sc = 1;
  }
  for (int r = sr; r < n; r += 2) {
    for (int c = sc; c < m; c += 2) {
      char z = gfc(r, c);
      if (x) {
        --x;
        re[r][c] = re[r + 1][c] = re[r][c + 1] = re[r + 1][c + 1] = z;
        continue;
      }
      if (b > 1) {
        b -= 2;
        re[r][c] = re[r + 1][c] = z;
        re[r][c + 1] = re[r + 1][c + 1] = z + 1;
        continue;
      }
      if (a > 1) {
        a -= 2;
        re[r][c] = re[r][c + 1] = z;
        re[r + 1][c] = re[r + 1][c + 1] = z + 1;
        continue;
      }
      goto IMP;
    }
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      printf("%c", re[r][c]);
    }
    printf("\n");
  }
  return 0;
IMP:
  printf("IMPOSSIBLE");
}
