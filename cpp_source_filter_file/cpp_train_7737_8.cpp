#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int h[1086][1086];
int f[1086][1086], g[1086][1086];
long long sum[1086][1086];
int q[1086], l, r;
bool vis[1086][1086];
struct Node {
  int x, y;
  long long z;
  inline friend bool operator<(Node a, Node b) {
    return a.z ^ b.z ? a.z > b.z : a.y ^ b.y ? a.y > b.y : a.x > b.x;
  }
} ans[1086 * 1086];
int k;
priority_queue<Node> Q;
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= n; i++) {
    l = 1, r = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%d", &h[i][j]);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + h[i][j];
      while (l <= r && q[l] + b - 1 < j) ++l;
      while (l <= r && h[i][j] <= h[i][q[r]]) --r;
      q[++r] = j;
      if (j >= b) f[i][j - b + 1] = h[i][q[l]];
    }
  }
  for (int j = 1; j + b - 1 <= m; j++) {
    l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
      while (l <= r && q[l] + a - 1 < i) ++l;
      while (l <= r && f[i][j] <= f[q[r]][j]) --r;
      q[++r] = i;
      if (i >= a) g[i - a + 1][j] = f[q[l]][j];
    }
  }
  for (int i = 1; i + a - 1 <= n; i++) {
    for (int j = 1; j + b - 1 <= m; j++) {
      Q.push((Node){i, j,
                    sum[i + a - 1][j + b - 1] - sum[i - 1][j + b - 1] -
                        sum[i + a - 1][j - 1] + sum[i - 1][j - 1] -
                        1ll * a * b * g[i][j]});
    }
  }
  while (!Q.empty()) {
    Node node = Q.top();
    Q.pop();
    if (!vis[node.x][node.y] && !vis[node.x + a - 1][node.y] &&
        !vis[node.x][node.y + b - 1] && !vis[node.x + a - 1][node.y + b - 1]) {
      ans[++k] = node;
      for (int i = node.x; i <= node.x + a - 1; i++) {
        for (int j = node.y; j <= node.y + b - 1; j++) {
          vis[i][j] = true;
        }
      }
    }
  }
  printf("%d\n", k);
  for (int i = 1; i <= k; i++) {
    printf("%d %d %lld\n", ans[i].x, ans[i].y, ans[i].z);
  }
}
