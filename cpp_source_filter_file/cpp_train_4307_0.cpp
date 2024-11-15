#include <bits/stdc++.h>
template <class K>
inline bool chkmin(K &a, K b) {
  return a > b ? a = b, true : false;
}
template <class K>
inline bool chkmax(K &a, K b) {
  return a < b ? a = b, true : false;
}
using namespace std;
const int oo = 0x3f3f3f3f;
const int maxn = 200 + 1;
int N, M, K, G[maxn][maxn], path[maxn][maxn], sest[maxn], st[maxn], ed[maxn],
    vis[maxn], dp[maxn], cur;
bool mt[maxn][maxn];
int dfs(int u, int v) {
  if (vis[u] == cur) return dp[u];
  vis[u] = cur;
  int ret = -1;
  for (int i = 1; i <= N; i++)
    if (G[u][i] == 1 && G[u][i] + G[i][v] == G[u][v]) chkmax(ret, dfs(i, v));
  return dp[u] = min(ret < 0 ? oo : ret, sest[u] + 1);
  ;
}
int main() {
  scanf("%d%d%d%d", &N, &M, &st[0], &ed[0]);
  for (int i = 1; i <= N; i++) {
    sest[i] = oo;
    for (int j = i + 1; j <= N; j++) G[j][i] = G[i][j] = oo;
  }
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u][v] = 1;
  }
  for (int t = 1; t <= N; t++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) chkmin(G[i][j], G[i][t] + G[t][j]);
  scanf("%d", &K);
  for (int i = 1; i <= K; ++i) {
    scanf("%d%d", &st[i], &ed[i]);
    int &u = st[i], &v = ed[i];
    for (int j = 1; j <= N; ++j)
      if (G[u][j] + G[j][v] == G[u][v] && G[u][j] < oo) path[i][G[u][j]]++;
    for (int j = 1; j <= N; ++j)
      if (G[u][j] + G[j][v] == G[u][v] && G[u][j] < oo && path[i][G[u][j]] == 1)
        mt[i][j] = true;
  }
  sest[ed[0]] = 0;
  while (true) {
    bool cab = false;
    for (int i = 1; i <= K; ++i)
      for (int j = 1; j <= N; ++j)
        if (mt[i][j]) {
          cur++;
          cab = chkmin(sest[j], dfs(j, ed[i]));
        }
    if (!cab) break;
  }
  if (sest[st[0]] >= oo)
    puts("-1");
  else
    printf("%d\n", sest[st[0]]);
  return 0;
}
