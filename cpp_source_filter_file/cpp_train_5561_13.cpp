#include <bits/stdc++.h>
int N, M, K, s[2505][2005], P[7], Q[7];
long long ans;
int S(int a, int b, int c, int d) {
  return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
}
void work(int a, int b, int c, int d) {
  int m;
  if (a == c && b == d) {
    ans += S(a, b, c, d) == K;
    return;
  }
  if (c - a > d - b) {
    m = (a + c) >> 1;
    for (int i = b; i <= d; i++) {
      for (int j = 0; j <= K; j++) P[j] = m - a + 1, Q[j] = c - m;
      for (int j = i; j >= b; j--) {
        for (int k = 0; k <= K; k++)
          for (; P[k] && S(m - P[k] + 1, j, m, i) > k; P[k]--)
            ;
        for (int k = 0; k <= K; k++)
          for (; Q[k] && S(m + 1, j, m + Q[k], i) > k; Q[k]--)
            ;
        for (int k = 0; k <= K; k++)
          ans += 1ll * (P[k] - (!k ? 0 : P[k - 1])) *
                 (Q[K - k] - (k == K ? 0 : Q[K - k - 1]));
      }
    }
    work(a, b, m, d), work(m + 1, b, c, d);
  } else {
    m = (b + d) >> 1;
    for (int i = a; i <= c; i++) {
      for (int j = 0; j <= K; j++) P[j] = m - b + 1, Q[j] = d - m;
      for (int j = i; j >= a; j--) {
        for (int k = 0; k <= K; k++)
          for (; P[k] && S(j, m - P[k] + 1, i, m) > k; P[k]--)
            ;
        for (int k = 0; k <= K; k++)
          for (; Q[k] && S(j, m + 1, i, m + Q[k]) > k; Q[k]--)
            ;
        for (int k = 0; k <= K; k++)
          ans += 1ll * (P[k] - (!k ? 0 : P[k - 1])) *
                 (Q[K - k] - (k == K ? 0 : Q[K - k - 1]));
      }
    }
    work(a, b, c, m), work(a, m + 1, c, d);
  }
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  char c[2505];
  for (int i = 1; i <= N; i++) {
    scanf("%s", c);
    for (int j = 1; j <= M; j++)
      s[i][j] = (c[j - 1] == '1') + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
  }
  work(1, 1, N, M), printf("%I64d\n", ans);
}
