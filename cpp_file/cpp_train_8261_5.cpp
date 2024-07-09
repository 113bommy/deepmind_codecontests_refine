#include <bits/stdc++.h>
using namespace std;
long long dp[5][5][40][40][40];
long long n, h;
long long answ;
long move(long x) {
  if (x == 0) return x;
  if (x + 1 == h) return 0;
  return x + 1;
}
bool isok(long hh, long x) {
  if (x > 0) return 1;
  if (hh < h) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  dp[1][1][0][0][0] = 4;
  cin >> n >> h;
  for (int qh = 1; qh <= n; qh++) {
    for (int i = 0; i <= h; i++)
      for (int j = 0; j <= h; j++)
        for (int q = 0; q <= h; q++) {
          dp[1 - qh % 2][1][i][j][q] = 0;
          dp[1 - qh % 2][0][i][j][q] = 0;
          while (dp[qh % 2][1][i][j][q] >= 1000000009)
            dp[qh % 2][1][i][j][q] -= 1000000009;
          while (dp[qh % 2][0][i][j][q] >= 1000000009)
            dp[qh % 2][0][i][j][q] -= 1000000009;
        }
    for (int i = 0; i <= h; i++)
      for (int j = 0; j <= h; j++)
        for (int q = 0; q <= h; q++)
          if (dp[qh % 2][0][i][j][q] + dp[qh % 2][1][i][j][q]) {
            dp[(qh + 1) % 2][1][move(i)][move(j)][move(q)] +=
                dp[qh % 2][1][i][j][q];
            dp[(qh + 1) % 2][0][move(i)][move(j)][move(q)] +=
                dp[qh % 2][0][i][j][q];
            dp[(qh + 1) % 2][isok(qh, i)][0][move(j)][move(q)] +=
                dp[qh % 2][0][i][j][q];
            dp[(qh + 1) % 2][isok(qh, i)][(h == 1 ? 0 : 1)][move(j)][move(q)] +=
                dp[qh % 2][1][i][j][q];
            dp[(qh + 1) % 2][isok(qh, j)][0][move(i)][move(q)] +=
                dp[qh % 2][0][i][j][q];
            dp[(qh + 1) % 2][isok(qh, j)][(h == 1 ? 0 : 1)][move(i)][move(q)] +=
                dp[qh % 2][1][i][j][q];
            dp[(qh + 1) % 2][isok(qh, q)][0][move(j)][move(i)] +=
                dp[qh % 2][0][i][j][q];
            dp[(qh + 1) % 2][isok(qh, q)][(h == 1 ? 0 : 1)][move(j)][move(i)] +=
                dp[qh % 2][1][i][j][q];
          }
  }
  for (int i = 0; i <= h; i++)
    for (int j = 0; j <= h; j++)
      for (int q = 0; q <= h; q++) {
        if (i || j || q) answ += dp[n % 2][0][i][j][q];
        answ += dp[n % 2][1][i][j][q];
      }
  cout << answ % 1000000009 << endl;
  cin.get();
  cin.get();
  return 0;
}
