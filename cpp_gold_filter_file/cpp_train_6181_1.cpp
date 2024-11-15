#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5, MAXM = 62;
bitset<MAXN> Map[MAXM + 5], F[MAXM + 5];
int tot, N, Ok[MAXM + 5], Ans[MAXN];
long long All;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    long long Num;
    scanf("%I64d", &Num);
    All ^= Num;
    for (int j = 0; j <= MAXM; j++)
      if (Num & (1ll << j)) Map[j][i] = 1;
  }
  for (int j = 0; j < 2; j++) {
    for (int i = MAXM; i >= 0; i--)
      if (((All >> i) & 1) == j) {
        F[++tot] = Map[i], Ok[tot] = N + 2, F[tot][N + 1] = 1 - j;
        for (int k = 1; k < tot; k++)
          if (F[tot][Ok[k]]) F[tot] ^= F[k];
        for (int k = 1; k <= N; k++)
          if (F[tot][k]) {
            Ok[tot] = k;
            break;
          }
        if (Ok[tot] > N) {
          tot--;
          continue;
        }
        for (int k = 1; k < tot; k++)
          if (F[k][Ok[tot]]) F[k] ^= F[tot];
      }
  }
  for (int i = 1; i <= tot; i++) Ans[Ok[i]] = F[i][N + 1];
  for (int i = 1; i <= N; i++) printf("%d ", 2 - Ans[i]);
}
