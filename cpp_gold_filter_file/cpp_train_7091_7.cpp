#include <bits/stdc++.h>
using namespace std;
const int MaxP = 12345;
int T, i, j, c, x[1010], w[26], s[200][26];
long long n;
char C[1010];
bool v[26];
struct Matrix {
  int M[124][124];
  Matrix operator*(const Matrix a) const {
    Matrix b;
    memset(b.M, 0, sizeof(b.M));
    for (int i = 0; i < T; i++)
      for (int j = 0; j < T; j++)
        for (int k = 0; k < T; k++)
          b.M[i][j] = (b.M[i][j] + M[i][k] * a.M[k][j]) % MaxP;
    return b;
  }
} A, B;
void calc() {
  T = 1;
  for (i = 0; i < 26; i++)
    if (w[i] > 0) T *= w[i];
  for (i = 1; i < T; i++) {
    memcpy(s[i], s[i - 1], sizeof(s[i]));
    s[i][25] = s[i - 1][25] + 1;
    for (j = 25; j > -1; j--)
      if (s[i][j] >= w[j]) {
        s[i][j] = 0;
        s[i][j - 1]++;
      } else
        break;
  }
}
int pd(int x, int y) {
  int g = 0, flag = 0;
  for (int i = 0; i < 26; i++) {
    if (w[i] == 1) g++;
    if (w[i] > 1 && ((s[y][i] + 1) % w[i] == s[x][i])) {
      if (flag) return 0;
      flag = 1;
      continue;
    }
    if (s[x][i] != s[y][i]) return 0;
  }
  if (flag) return 1;
  return g;
}
void Make_Matrix() {
  for (i = 0; i < T; i++)
    for (j = 0; j < T; j++) A.M[i][j] = pd(i, j);
}
void Qck(long long n) {
  if (n == 1) {
    B = A;
    return;
  }
  Qck(n >> 1);
  B = B * B;
  if (n & 1) B = B * A;
}
bool PD(int X) {
  memset(v, 0, sizeof(v));
  for (int i = 1; i <= c; i++)
    if (s[X][C[i] - 'A'] % x[i] == 0) v[C[i] - 'A'] = 1;
  for (int i = 0; i < 26; i++)
    if (!v[i] && w[i] > 0) return 0;
  return 1;
}
int ANS() {
  int ret = 0;
  for (i = 0; i < T; i++)
    if (PD(i)) ret += B.M[i][0];
  return ret % MaxP;
}
int main() {
  scanf("%I64d%d\n", &n, &c);
  for (i = 1; i <= c; i++) {
    C[i] = getchar();
    scanf("%d\n", x + i);
    if (w[C[i] - 'A'] == 0)
      w[C[i] - 'A'] = x[i];
    else
      w[C[i] - 'A'] *= x[i];
  }
  if (!n) {
    printf("%d\n", 1);
    return 0;
  }
  calc();
  Make_Matrix();
  Qck(n);
  printf("%d\n", ANS());
  return 0;
}
