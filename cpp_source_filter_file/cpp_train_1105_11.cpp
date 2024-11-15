#include <bits/stdc++.h>
using namespace std;
int g[100005], dp[100005], used[100005];
int f(int n) {
  int i, a, r = -1;
  for (i = 2; (i * (i + 1) / 2) <= n; i++) {
    if ((2 * n) % i == 0) {
      a = (2 * n) / i - (i - 1);
      if ((a & 1) || (a <= 0)) continue;
      a /= 2;
      used[dp[a + i - 1] ^ dp[a - 1]] = n;
      if (dp[a + i - 1] ^ dp[a - 1] == 0)
        if (r == -1) r = i;
    }
  }
  for (i = 0; used[i] == n; i++)
    ;
  dp[n] = i ^ dp[n - 1];
  return r;
}
int main() {
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  memset(used, 0, sizeof(used));
  g[1] = g[2] = -1;
  for (int i = 3; i < 100005; i++) g[i] = f(i);
  cout << g[n] << endl;
  return 0;
}
