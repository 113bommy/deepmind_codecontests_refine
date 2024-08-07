#include <bits/stdc++.h>
int N, M, i, K, Turn, Remain, tmp, X, Y, C;
long long B[1005], Ans, oo;
int P[1005], Cnt[1005];
int main() {
  scanf("%d%d", &N, &M);
  if ((N + M) & 1) {
    printf("0\n");
    return 0;
  }
  if (N < M) {
    tmp = N, N = M, M = tmp;
    Turn = 1;
  }
  scanf("%d", &K);
  for (i = 1; i <= N; ++i) P[i] = 1;
  for (i = 1; i <= K; ++i) {
    scanf("%d%d%d", &X, &Y, &C);
    if (Turn) tmp = X, X = Y, Y = tmp;
    ++Cnt[X], P[X] *= C;
  }
  scanf("%I64d", &oo);
  B[0] = 1;
  for (i = 1; i <= M; ++i) B[i] = B[i - 1] * 2ll % oo;
  Ans = 1, Remain = 0;
  for (i = 1; i <= N; ++i) {
    if (!Cnt[i] && !Remain)
      Remain = 1;
    else if (Cnt[i] == M) {
      if (P[i] == 1) {
        printf("0\n");
        return 0;
      }
    } else
      Ans = (Ans * B[M - Cnt[i] - 1]) % oo;
  }
  printf("%I64d\n", Ans);
  return 0;
}
