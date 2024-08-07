#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 205;
int edge[maxn][maxn];
int n, m;
int dis[maxn][maxn];
int calc(int u, int v) {
  int w = edge[u][v];
  int ans = INT_MAX;
  vector<pair<int, int> > lines(0);
  for (int i = 1; i <= n; i++) {
    int a = dis[i][u];
    int b = dis[i][v];
    int x = (w + b - a) >> 1;
    if (x >= w) {
      lines.push_back(make_pair(w, a + w));
    } else if (x <= 0) {
      lines.push_back(make_pair(0, b + w));
    } else {
      lines.push_back(make_pair(x, a + x));
    }
  }
  int left = 0, right = 0;
  for (auto line : lines) {
    int x, peak;
    tie(x, peak) = line;
    left = max(left, peak - x);
    right = max(right, peak - (w - x));
  }
  ans = min(left, right);
  map<int, int> highest;
  for (auto line : lines) {
    int x, peak;
    tie(x, peak) = line;
    highest[x] = max(highest[x], peak);
  }
  lines.clear();
  for (auto pr : highest) {
    lines.push_back(pr);
  }
  vector<pair<int, int> > lines2(0);
  lines2.push_back(lines.front());
  for (int i = 1; i < lines.size(); i++) {
    while (!lines2.empty()) {
      int x1, p1, x2, p2;
      tie(x2, p2) = lines[i];
      tie(x1, p1) = lines2.back();
      int x = (p1 - p2 + x1 + x2) >> 1;
      if (x > x1 && x < x2) {
        lines2.push_back(lines[i]);
        break;
      } else if (x <= x1) {
        lines2.pop_back();
      } else if (x >= x2) {
        break;
      }
    }
    if (lines2.empty()) lines2.push_back(lines[i]);
  }
  for (int i = 1; i < lines2.size(); i++) {
    int x1, p1, x2, p2;
    tie(x1, p1) = lines2[i - 1];
    tie(x2, p2) = lines2[i];
    int x = ((p1 - p2) + x1 + x2) >> 1;
    if (x >= x1 && x <= x2) {
      ans = min(ans, p1 - (x - x1));
    }
  }
  return ans;
}
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      edge[i][j] = dis[i][j] = inf;
    }
    edge[i][i] = dis[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    w <<= 1;
    edge[a][b] = min(edge[a][b], w);
    edge[b][a] = min(edge[b][a], w);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = edge[i][j];
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= n; i++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (edge[i][j] != inf) {
        ans = min(ans, calc(i, j));
      }
    }
  }
  cout << fixed << setprecision(2) << ans / 2.0 << endl;
  return 0;
}
