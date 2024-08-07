#include <bits/stdc++.h>
using namespace std;
typedef long long arr[1000010];
const long long mo = 1000000007;
arr Sum_gcd, prime, phi, F, F1, F2, F3;
long long N, M, tot;
bool vis[1000010];
inline void prepare(long long N) {
  phi[1] = 1;
  for (long long i = 2; i <= N; i++) {
    if (!vis[i]) prime[++tot] = i, phi[i] = i - 1;
    for (long long j = 1; j <= tot && i * prime[j] < N; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      } else
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (long long i = 1; i <= N; i++)
    for (long long j = 1; i * j <= N; j++)
      Sum_gcd[i * j] = (Sum_gcd[i * j] + i * phi[j]) % mo;
  for (long long i = 1; i <= N; i++) {
    F[i] = (mo - 3 * i * i % mo + i * (i + 1) * (2 * i + 1) / 3 % mo) % mo;
    F[i] = (F[i] + 2 * Sum_gcd[i]) % mo;
  }
  for (long long i = 1; i <= N; i++) {
    F1[i] = (F1[i - 1] + F[i]) % mo;
    F2[i] = (F2[i - 1] + F[i] * (i - 1) % mo) % mo;
    F3[i] = (F3[i - 1] + F[i] * (i - 1) % mo * (i - 1) % mo) % mo;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  prepare((int)1e6);
  while (T--) {
    scanf("%I64d%I64d", &N, &M);
    if (N > M) swap(N, M);
    printf(
        "%I64d\n",
        (((N * M % mo * F1[N] % mo) - (N + M) * F2[N] % mo + F3[N]) % mo + mo) %
            mo);
  }
  return 0;
}
