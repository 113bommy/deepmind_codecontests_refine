#include <bits/stdc++.h>
using namespace std;
int N, P;
signed long long dp[51][51][51][51];
signed long long p2[51];
const int CN = 101;
signed long long C[CN][CN];
signed long long CS[CN][2];
signed long long mo = 1000000007;
int col[51];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  for (i = 0; i < (CN); i++)
    for (j = 0; j <= i; j++) {
      C[i][j] = (j == 0 || j == i) ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % mo;
      (CS[i][j % 2] += C[i][j]) %= mo;
    }
  p2[0] = 1;
  for (i = 0; i < (50); i++) p2[i + 1] = p2[i] * 2 % mo;
  cin >> N >> P;
  for (i = 0; i < (N); i++) cin >> col[i];
  dp[0][0][0][0] = 1;
  signed long long ret = 0;
  for (int b0 = 0; b0 <= N; b0++)
    for (int b1 = 0; b1 <= N; b1++)
      for (int w0 = 0; w0 <= N; w0++)
        for (int w1 = 0; b0 + b1 + w0 + w1 <= N; w1++) {
          signed long long d = dp[b0][b1][w0][w1];
          int done = b0 + b1 + w0 + w1;
          if (col[done] == 0 || col[done] == -1) {
            signed long long pat = p2[b0 + b1 + w1];
            (dp[b0 + 1][b1][w0][w1] += d * pat % mo * CS[w0][0] % mo) %= mo;
            (dp[b0][b1 + 1][w0][w1] += d * pat % mo * CS[w0][1] % mo) %= mo;
          }
          if (col[done] == 1 || col[done] == -1) {
            signed long long pat = p2[b1 + w0 + w1];
            (dp[b0][b1][w0 + 1][w1] += d * pat % mo * CS[b0][0] % mo) %= mo;
            (dp[b0][b1][w0][w1 + 1] += d * pat % mo * CS[b0][1] % mo) %= mo;
          }
          if (b0 + b1 + w0 + w1 == N && (b0 + w0) % 2 == P)
            (ret += dp[b0][b1][w0][w1]) %= mo;
        }
  cout << ret % mo << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
