#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
int n, k;
long long l[1010], r[1010];
double p[1010], dp[1010][1010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  cin >> k;
  for (int i = 1; i <= n; i++) {
    long long cnt = 0;
    for (long long d = 1; 1; d *= 10) {
      if (d > r[i]) break;
      if (d >= l[i] && 2 * d - 1 <= r[i])
        cnt += d;
      else if (2 * d - 1 >= r[i]) {
        cnt += r[i] - max(d, l[i]) + 1;
        break;
      } else if (l[i] >= d && 2 * d - 1 >= l[i])
        cnt += min(2 * d - 1, r[i]) - l[i] + 1;
    }
    p[i] = cnt * 1.0 / (r[i] - l[i] + 1);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j) dp[i][j] += dp[i - 1][j - 1] * p[i];
      dp[i][j] += (1 - p[i]) * dp[i - 1][j];
    }
  }
  double ret = 0;
  for (int i = 1; i <= n; i++)
    if (i * 100 >= k * n) ret += dp[n][i];
  printf("%.12f\n", ret);
  return 0;
}
