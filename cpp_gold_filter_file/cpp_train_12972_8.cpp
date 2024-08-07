#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;
int N;
int X[MAXN];
int Y[MAXN];
double dist[MAXN][MAXN];
double dp[MAXN][MAXN][2];
double getDist(int a, int b) {
  return sqrt(1.0 * (X[a] - X[b]) * (X[a] - X[b]) +
              1.0 * (Y[a] - Y[b]) * (Y[a] - Y[b]));
}
double getdp(int a, int b, int dir) {
  if (dp[a][b][dir] > 0) return dp[a][b][dir];
  int c = (a + 1) % N, d = (b + N - 1) % N;
  if (b == c) return dp[a][b][dir] = dist[a][b];
  if (dir == 0)
    dp[a][b][0] = dist[a][b] +
                  max(getdp(c, b, 0) - dist[c][b] + dist[c][a], getdp(a, d, 1));
  else
    dp[a][b][1] = dist[a][b] +
                  max(getdp(a, d, 1) - dist[d][a] + dist[d][b], getdp(c, b, 0));
  return dp[a][b][dir];
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d %d", &X[i], &Y[i]);
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) dist[i][j] = dist[j][i] = getDist(i, j);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dp[i][j][0] = dp[i][j][1] = -1.0;
  double ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, getdp((i + 1) % N, i, 0));
    ans = max(ans, getdp((i + 1) % N, i, 1));
  }
  printf("%.10f\n", ans);
  return 0;
}
