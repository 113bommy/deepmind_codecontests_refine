#include <bits/stdc++.h>
using namespace std;
int x = 0, y = 0;
int cnt, k;
int per(int tt) {
  if (cnt == k) cout << y << " " << x << endl;
  cnt++;
  if (tt == 0)
    ++x;
  else if (tt == 1)
    ++y;
  else if (tt == 2)
    --x;
  else if (tt == 3)
    --y;
  return 0;
}
int run(int t, int k, int n) {
  if (n == 0) {
    return 1;
  }
  if (t > 0) {
    if (k == 0)
      return (run(-t, 1, n - 1) + per(2) + run(t, 0, n - 1) + per(3) +
              run(t, 0, n - 1) + per(0) + run(-t, 3, n - 1));
    if (k == 2)
      return (run(-t, 3, n - 1) + per(0) + run(t, 2, n - 1) + per(1) +
              run(t, 2, n - 1) + per(2) + run(-t, 1, n - 1));
  } else {
    if (k == 1)
      return (run(-t, 0, n - 1) + per(3) + run(t, 1, n - 1) + per(2) +
              run(t, 1, n - 1) + per(1) + run(-t, 2, n - 1));
    if (k == 3)
      return (run(-t, 2, n - 1) + per(1) + run(t, 3, n - 1) + per(0) +
              run(t, 3, n - 1) + per(3) + run(-t, 0, n - 1));
  }
}
int dp[11];
int main() {
  dp[1] = 1;
  for (int i = 2; i <= 10; i++) dp[i] = dp[i - 1] * 2 + 1;
  int n;
  cin >> n >> k;
  cnt = 0;
  run(1, 2, n);
  if (k == cnt) cout << dp[n] << " " << 0 << endl;
}
