#include <bits/stdc++.h>
using namespace std;
bool f1[51][51][26], f2[51][51][26];
int f[51][51], d[50][3];
int main() {
  char s1[52], s2[52], c, a, b;
  int len1, len2, i, j, k, l, n, ii, jj;
  gets(s1 + 1);
  gets(s2 + 1);
  len1 = strlen(s1 + 1);
  len2 = strlen(s2 + 1);
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    getchar();
    scanf("%c->%c%c", &c, &a, &b);
    d[50][0] = a - 'a';
    d[50][1] = b - 'a';
    d[50][2] = c - 'a';
  }
  memset(f1, false, sizeof(f1));
  memset(f2, false, sizeof(f2));
  for (i = 1; i <= len1; i++) f1[i][i][s1[i] - 'a'] = true;
  for (k = 2; k <= len1; k++)
    for (i = 1; i <= len1 - k + 1; i++) {
      j = i + k - 1;
      for (l = i; l < j; l++)
        for (ii = 1; ii <= n; ii++)
          if (f1[i][l][d[ii][0]] && f1[l + 1][j][d[ii][1]])
            f1[i][j][d[ii][2]] = true;
    }
  for (i = 1; i <= len2; i++) f2[i][i][s2[i] - 'a'] = true;
  for (k = 2; k <= len2; k++)
    for (i = 1; i <= len2 - k + 1; i++) {
      j = i + k - 1;
      for (l = i; l < j; l++)
        for (ii = 1; ii <= n; ii++)
          if (f2[i][l][d[ii][0]] && f2[l + 1][j][d[ii][1]])
            f2[i][j][d[ii][2]] = true;
    }
  memset(f, 63, sizeof(f));
  f[0][0] = 0;
  int tt = f[1][1];
  for (i = 0; i <= len1; i++)
    for (j = 0; j <= len2; j++)
      if (f[i][j] != tt)
        for (ii = i + 1; ii <= len1; ii++)
          for (jj = j + 1; jj <= len2; jj++)
            for (k = 0; k < 26; k++)
              if ((f1[i + 1][ii][k] & f2[j + 1][jj][k]) == true) {
                f[ii][jj] = min(f[ii][jj], f[i][j] + 1);
              }
  if (f[len1][len2] == tt)
    printf("-1\n");
  else
    printf("%d\n", f[len1][len2]);
  return 0;
}
