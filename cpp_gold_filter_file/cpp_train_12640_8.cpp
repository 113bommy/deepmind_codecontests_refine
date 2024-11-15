#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111;
const long long int MOD = 1e9 + 7;
int N, S;
int mx[MAXN];
int beg[MAXN];
int sum[MAXN];
long long int dn[MAXN][MAXN * MAXN];
long long int cm[MAXN * MAXN][MAXN];
long long int comb(int n, int r) {
  if (cm[n][r]) return cm[n][r];
  if (r > n) return 0LL;
  if (n == r || !r) return cm[n][r] = 1;
  if (r == 1 || r == n - 1LL) return cm[n][r] = n;
  return cm[n][r] = (comb(n - 1, r) + comb(n - 1, r - 1)) % MOD;
}
long long int f(int pl, int cur) {
  if (pl == N + 1) return cur ? 0LL : 1LL;
  long long int &rev = dn[pl][cur];
  if (rev != -1) return rev;
  rev = 0LL;
  cur += beg[pl];
  for (int i = 0; i <= min(cur, mx[pl]); i++)
    rev = (rev + f(pl + 1, cur - i) * comb(cur, i)) % MOD;
  return rev;
}
int main() {
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN * MAXN; j++) dn[i][j] = (long long int)-1;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", beg + i);
    S += beg[i];
  }
  for (int i = 1; i <= N; i++) scanf("%d", mx + i);
  long long int res = f(1, 0);
  for (int i = 1; i <= N; i++) {
    res = (res * comb(S, beg[i])) % MOD;
    S -= beg[i];
  }
  printf("%I64d\n", res);
  return 0;
}
