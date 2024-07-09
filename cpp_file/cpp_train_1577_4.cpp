#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
inline int read() {
  int s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s;
}
int n, m;
int a[N], b[N];
vector<int> G[N];
inline int dis(int i, int j) { return i > j ? (n - i + j) : (j - i); }
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    a[i] = read(), b[i] = read();
    G[a[i]].push_back(dis(a[i], b[i]));
  }
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, (int)G[i].size());
    sort(G[i].begin(), G[i].end());
  }
  int ans = (mx - 1) * n;
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = i; j <= n; j++) {
      if (!G[j].size()) continue;
      if (G[j].size() == mx)
        t = max(t, j + G[j][0] - i);
      else if (G[j].size() == mx - 1) {
        int tmp = j + G[j][0];
        if (tmp > n) tmp -= n;
        if (tmp > j) continue;
        t = max(t, tmp - i);
      }
    }
    for (int j = 1; j < i; j++) {
      if (!G[j].size()) continue;
      if (G[j].size() == mx)
        t = max(t, j + G[j][0] + n - i);
      else if (G[j].size() == mx - 1) {
        int tmp = j + G[j][0];
        t = max(t, tmp - i);
      };
    }
    printf("%d ", ans + t);
  }
  return 0;
}
