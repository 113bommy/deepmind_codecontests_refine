#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int _max = 1e9;
int a[maxn], b[maxn];
int dp[maxn];
vector<int> pos[maxn];
int main() {
  int n, m, s, e;
  scanf("%d%d%d%d", &n, &m, &s, &e);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    pos[b[i]].push_back(i);
  }
  for (int i = 1; i <= maxn; i++) pos[i].push_back(_max);
  int time = s / e;
  dp[0] = 0;
  for (int i = 1; i <= time; i++) dp[i] = _max - 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = time; j > 0; j--) {
      dp[j] = min(dp[j],
                  *upper_bound(pos[a[i]].begin(), pos[a[i]].end(), dp[j - 1]));
      if ((s - j * e - 2 - i >= dp[j]) && j > ans) ans = j;
    }
  }
  printf("%d\n", ans);
  return 0;
}
