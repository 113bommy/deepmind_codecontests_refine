#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
int zzz = 0;
const int NN = 100022;
vector<pair<long long, long long>> cr;
map<pair<int, int>, int> mp;
int N, M, L, k;
int dp[441][55][2][2][2];
int in[444];
void made(int &a, int b) {
  if (b > a) a = b;
}
int sign[2] = {1, -1};
int main() {
  cin >> N >> k;
  for (int i = 1; i <= N; i++) {
    cin >> in[i];
  }
  for (int i = 0; i <= N + 1; i++) {
    for (int j = 0; j <= k + 1; j++) {
      for (int e = 0; e < 2; e++) {
        for (int c1 = 0; c1 < 2; c1++) {
          for (int c2 = 0; c2 < 2; c2++) {
            dp[i][j][e][c1][c2] = -100000000;
            if (j == 0 && e == 0) {
              dp[i][j][e][c1][c2] = 0;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= k; j++) {
      for (int e = 0; e < 2; e++) {
        for (int c1 = 0; c1 < 2; c1++) {
          for (int c2 = 0; c2 < 2; c2++) {
            if (dp[i][j][e][c1][c2] == -100000000) continue;
            if (j == 0) {
              dp[i + 1][j + 1][1][c1][c2] =
                  max(dp[i + 1][j + 1][1][c1][c2], sign[c2] * in[i + 1]);
            } else if (j <= k - 1) {
              dp[i + 1][j][1][c1][c2] =
                  max(dp[i + 1][j][1][c1][c2],
                      (j == 1 ? 0 : -sign[c1] * in[i + 1]) +
                          sign[c2] * in[i + 1] + dp[i][j][e][c1][c2]);
              if (e == 0)
                dp[i + 1][j][e][c1][c2] =
                    max(dp[i + 1][j][e][c1][c2], dp[i][j][e][c1][c2]);
              if (e != 0) {
                for (int x = 0; x < 2; x++) {
                  dp[i + 1][j + 1][0][c2][x] =
                      max(dp[i + 1][j + 1][0][c2][x], dp[i][j][e][c1][c2]);
                  dp[i + 1][j + 1][1][c2][x] =
                      max(dp[i + 1][j + 1][1][c2][x],
                          -sign[c2] * in[i + 1] +
                              (j == k - 1 ? 0 : sign[x] * in[i + 1]) +
                              dp[i][j][e][c1][c2]);
                }
              }
            } else if (j == k) {
              dp[i + 1][j][1][c1][c2] =
                  max(dp[i + 1][j][1][c1][c2],
                      -sign[c1] * in[i + 1] + dp[i][j][e][c1][c2]);
              if (e == 0) {
                dp[i + 1][j][e][c1][c2] =
                    max(dp[i + 1][j][e][c1][c2], dp[i][j][e][c1][c2]);
              }
            }
          }
        }
      }
    }
  }
  int ans = -100000000;
  for (int i = 0; i <= N; i++) {
    for (int c1 = 0; c1 < 2; c1++) {
      for (int c2 = 0; c2 < 2; c2++) {
        ans = max(ans, dp[i][k][1][c1][c2]);
      }
    }
  }
  printf("%d", ans);
  return 0;
  system("pause");
}
