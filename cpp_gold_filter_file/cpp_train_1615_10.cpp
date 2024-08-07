#include <bits/stdc++.h>
using namespace std;
const int MAXN = 123456 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int BASE = 31;
int N, M;
vector<int> G[MAXN];
bool attack[MAXN];
int maxLevel, minNode1 = MAXN, minNode2 = MAXN, sumEdges;
bool canGo[MAXN];
void findDiameter1(int p, int r, int level) {
  for (int i = 0; i < G[r].size(); ++i) {
    int u = G[r][i];
    if (u != p) {
      findDiameter1(r, u, level + 1);
      if (canGo[u]) canGo[r] = 1;
    }
  }
  if (attack[r]) {
    canGo[r] = 1;
    if (level == maxLevel) {
      minNode1 = min(r, minNode1);
    } else if (level > maxLevel) {
      maxLevel = level;
      minNode1 = r;
    }
  }
}
void findDiameter2(int p, int r, int level) {
  for (int i = 0; i < G[r].size(); ++i) {
    int u = G[r][i];
    if (u != p && canGo[u]) {
      sumEdges += 2;
      findDiameter2(r, u, level + 1);
    }
  }
  if (attack[r]) {
    if (level == maxLevel) {
      minNode2 = min(r, minNode2);
    } else if (level > maxLevel) {
      maxLevel = level;
      minNode2 = r;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  int u, v;
  for (int i = 0; i < N - 1; ++i) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 0; i < M; ++i) {
    cin >> u;
    attack[u] = 1;
  }
  findDiameter1(-1, u, 0);
  findDiameter2(-1, minNode1, 0);
  cout << min(minNode1, minNode2) << '\n';
  cout << sumEdges - maxLevel << '\n';
  return 0;
}
