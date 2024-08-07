#include <bits/stdc++.h>
int Which[10][10], t;
struct REC {
  int c[10][10];
} Ans, Rec, Tmp, A;
void Update(int& a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
void Mult(REC& a, REC b) {
  int i, j, k;
  memcpy(Tmp.c, a.c, sizeof a.c);
  memset(a.c, 0, sizeof a.c);
  for (i = 0; i <= t; i++)
    for (j = 0; j <= t; j++)
      for (k = 0; k <= t; k++)
        Update(a.c[i][j], (1ll * Tmp.c[i][k] * b.c[k][j]) % 1000000007);
}
int Calc(int N) {
  if (N == 0) return 0;
  int i, j, Last(4);
  N--;
  memcpy(Rec.c, A.c, sizeof Rec.c);
  memset(Ans.c, 0, sizeof Ans.c);
  for (i = 0; i <= t; i++) Ans.c[i][i] = 1;
  for (; N; N >>= 1) {
    if (N & 1) Mult(Ans, Rec);
    Mult(Rec, Rec);
  }
  for (i = 0; i < t; i++) Update(Last, Ans.c[i][t]);
  return Last;
}
int GetAns(int N) {
  return ((Calc(N) + Calc((N + 1) / 2)) % 1000000007 * 1ll * 500000004) %
         1000000007;
}
int main() {
  int Ans, i, j, k, L, R;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if ((i ^ j) > 1) Which[i][j] = t++;
  for (i = 0; i <= t; i++) A.c[i][t] = 1;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if ((i ^ j) > 1)
        for (k = 0; k < 4; k++)
          if ((k ^ j) > 1 && !(i == 3 && j == 0 && k == 2) &&
              !(i == 2 && j == 0 && k == 3))
            A.c[Which[i][j]][Which[j][k]] = 1;
  scanf("%d%d", &L, &R);
  Ans = (GetAns(R) - GetAns(L - 1) + 1000000007) % 1000000007;
  printf("%d\n", Ans);
  return 0;
}
