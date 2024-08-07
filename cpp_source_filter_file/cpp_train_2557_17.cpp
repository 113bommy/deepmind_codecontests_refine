#include <bits/stdc++.h>
using namespace std;
int N, M, K, a, b, tot, E, size;
vector<int> G[1000005];
bool visit[1000005];
void dfs(int x) {
  visit[x] = 1;
  ++size;
  for (unsigned int i = 0; i < G[x].size(); ++i)
    if (!visit[G[x][i]]) dfs(G[x][i]);
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= N; ++i)
    if (!visit[i]) {
      ++tot;
      size = 0;
      dfs(i);
      E += min(K, size);
    }
  --tot;
  if (K == 1)
    printf("%d\n", tot - 1);
  else {
    E /= 2;
    printf("%d\n", (E - tot >= 0) ? 0 : (tot - E));
  }
}
