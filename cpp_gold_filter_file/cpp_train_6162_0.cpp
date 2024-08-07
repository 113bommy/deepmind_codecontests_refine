#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int n, m, q;
long long add[510], a[510][510], dp[510][510], gox[510][510], goy[510][510];
vector<pair<int, int> > vx[510][510], vy[510][510];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; i++) {
    int x, y, t, d, e;
    scanf("%d%d%d%d%d", &x, &y, &d, &t, &e);
    if (x + y >= t && (x + y - t) % 4 == 0) {
      a[x][y] += e;
      if (x + y + d >= t && (x + y + d - t) % 4 == 2)
        vx[x][y].push_back({x + d, e});
      else
        vx[x][y].push_back({n, e});
      if (x + y + d >= t && (x + y + d - t) % 4 == 3)
        vy[x][y].push_back({y + d, e});
      else
        vy[x][y].push_back({m, e});
    }
    if (x + y >= t && (x + y - t) % 4 == 1) {
      a[x + d][y - d] += e;
      vx[x + d][y - d].push_back({n, e});
      if (x + y + d >= t && (x + y + d - t) % 4 == 2)
        vy[x + d][y - d].push_back({y, e});
      else
        vy[x + d][y - d].push_back({m, e});
    }
    if (x + y + d >= t && (x + y + d - t) % 4 == 2) {
      a[x + d][y] += e;
      vx[x + d][y].push_back({n, e});
      vy[x + d][y].push_back({m, e});
    }
    if (x + y + d >= t && (x + y + d - t) % 4 == 3) {
      a[x][y + d] += e;
      vx[x][y + d].push_back({n, e});
      vy[x][y + d].push_back({m, e});
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      dp[x][y] = INF;
      {
        long long cur = 0;
        for (auto it : vx[x][y]) {
          cur += it.second;
          add[it.first] += it.second;
        }
        for (int k = x; k <= n; k++) {
          cur -= add[k];
          gox[y][k] += cur;
          add[k] = 0;
        }
      }
      {
        long long cur = 0;
        for (auto it : vy[x][y]) {
          cur += it.second;
          add[it.first] += it.second;
        }
        for (int k = y; k <= m; k++) {
          cur -= add[k];
          goy[k][x] += cur;
          add[k] = 0;
        }
      }
    }
  }
  dp[0][0] = a[0][0];
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      dp[x][y] -= a[x][y];
      for (int k = x + 1; k < n; k++)
        dp[k][y] = min(dp[k][y], dp[x][y] + gox[y][k]);
      for (int k = y + 1; k < m; k++)
        dp[x][k] = min(dp[x][k], dp[x][y] + goy[k][x]);
      {
        long long cur = 0;
        for (auto it : vx[x][y]) {
          cur += it.second;
          add[it.first] += it.second;
        }
        for (int k = x; k <= n; k++) {
          cur -= add[k];
          gox[y][k] -= cur;
          add[k] = 0;
        }
      }
      {
        long long cur = 0;
        for (auto it : vy[x][y]) {
          cur += it.second;
          add[it.first] += it.second;
        }
        for (int k = y; k <= m; k++) {
          cur -= add[k];
          goy[k][x] -= cur;
          add[k] = 0;
        }
      }
    }
  }
  printf("%lld", dp[n - 1][m - 1]);
  return 0;
}
