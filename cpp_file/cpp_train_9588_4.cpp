#include <bits/stdc++.h>
using namespace std;
int cnt, flag[105] = {1, 1}, pri[105], mu[105] = {0, 1};
long long sum[105];
void Mulset() {
  int i, j;
  for (i = 2; i <= 105; i++) {
    if (flag[i] == 0) {
      pri[++cnt] = i;
      mu[i] = -1;
    }
    for (j = 1; j <= cnt && i * pri[j] <= 105; j++) {
      flag[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        mu[i * pri[j]] = 0;
        break;
      }
      mu[i * pri[j]] = -mu[i];
    }
  }
}
int main(void) {
  long long ans, n;
  int T, i;
  Mulset();
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%lld", &n);
    for (i = 2; i <= 60; i++) {
      sum[i] = (long long)powl((long double)n + 0.1, (long double)1.0 / i) - 1;
      ans += sum[i] * mu[i];
    }
    printf("%lld\n", n - 1 + ans);
  }
  return 0;
}
