#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, ts, P[N], H[N], K[N], R[N], sz[N], F[N];
string S[N];
vector<int> Adj[N], Q[N];
map<string, int> MP;
map<int, int> M[N];
void Predfs(int v) {
  sz[v] = 1;
  for (int &u : Adj[v]) H[u] = H[v] + 1, Predfs(u), sz[v] += sz[u];
  for (int i = 0; i < Adj[v].size(); i++)
    if (sz[Adj[v][i]] > sz[Adj[v][0]]) swap(Adj[v][i], Adj[v][0]);
}
void Add(int v, int w) {
  M[H[v]][F[v]] += w;
  if (w == -1 && !M[H[v]][F[v]]) M[H[v]].erase(F[v]);
  for (int &u : Adj[v]) Add(u, w);
}
void DFS(int v) {
  M[H[v]][F[v]]++;
  if (!Adj[v].size()) return;
  for (int &u : Adj[v])
    if (u != Adj[v][0]) DFS(u), Add(u, -1);
  DFS(Adj[v][0]);
  for (int &u : Adj[v])
    if (u != Adj[v][0]) Add(u, 1);
  for (int &id : Q[v]) R[id] = M[K[id] + H[v]].size();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> S[i] >> P[i];
    Adj[P[i]].push_back(i);
    if (!MP[S[i]]) MP[S[i]] = ++ts;
    F[i] = MP[S[i]];
  }
  cin >> q;
  for (int i = 1, v; i <= q; i++) cin >> v >> K[i], Q[v].push_back(i);
  Predfs(0);
  DFS(0);
  for (int i = 1; i <= q; i++) cout << R[i] << '\n';
  return (0);
}
