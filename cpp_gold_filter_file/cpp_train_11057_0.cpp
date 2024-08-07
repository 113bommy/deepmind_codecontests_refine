#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1000 * 100 + 100;
int n, sz[N];
vector<pair<int, int>> adj[N];
long long G, B;
void makePlaces(int root, int par = -1) {
  for (auto u : adj[root])
    if (u.first ^ par) {
      makePlaces(u.first, root);
      G += 1LL * (sz[u.first] & 1) * u.second;
      B += 1LL * min(n - sz[u.first], sz[u.first]) * u.second;
      sz[root] += sz[u.first];
    }
  sz[root]++;
}
int main() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &n);
    n <<= 1;
    for (int i = 1, v, u, w; i < n; i++) {
      scanf("%d%d%d", &v, &u, &w);
      adj[v].push_back({u, w});
      adj[u].push_back({v, w});
    }
    makePlaces(1);
    printf("%lld %lld\n", G, B);
    for (int i = 1; i <= n; i++) adj[i].clear(), sz[i] = 0;
    G = B = 0;
  }
  return 0;
}
