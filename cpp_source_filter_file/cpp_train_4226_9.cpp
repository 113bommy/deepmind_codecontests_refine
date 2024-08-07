#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 50 * 1000 + 10;
int G, S, n, m, par[N];
int get_par(int v) { return par[v] == v ? v : par[v] = get_par(par[v]); }
struct edge {
  int v = 0, u = 0, g = 0, s = 0;
  bool operator<(edge b) const {
    return make_pair(make_pair(s, v), u) < make_pair(make_pair(b.s, b.v), b.u);
  }
} e[M];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> G >> S;
  for (int i = 0; i < m; i++) cin >> e[i].v >> e[i].u >> e[i].g >> e[i].s;
  sort(e, e + m, [](edge x, edge y) { return x.g < y.g; });
  long long ans = 1LL << 60;
  set<edge> E;
  for (int i = 0; i < m; i++) {
    E.insert(e[i]);
    iota(par, par + n + 1, 0);
    edge goodbye;
    for (auto e : E) {
      int v = e.v, u = e.u;
      v = get_par(v), u = get_par(u);
      if (v == u)
        goodbye = e;
      else
        par[u] = v;
    }
    E.erase(goodbye);
    if ((int)(E.size()) == n - 1)
      ans = min(1LL * G * e[i].g + 1LL * S * (*--E.end()).s, ans);
  }
  cout << (ans < 1LL << 55 ? ans : -1) << '\n';
  return 0;
}
