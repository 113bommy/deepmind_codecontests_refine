#include <bits/stdc++.h>
using namespace std;
bool isPrime[20010];
vector<int> primes;
int N;
int A[210];
void makePrime() {
  memset(isPrime, true, sizeof(isPrime));
  for (int i = 2; i < 20010; i++) {
    if (isPrime[i]) primes.push_back(i);
    for (int p : primes) {
      if (i * p >= 20010) break;
      isPrime[i * p] = false;
      if (i % p == 0) break;
    }
  }
}
struct Dinic {
  struct Edge {
    int v1, v2, f, c;
  };
  int N;
  vector<vector<int>> vc;
  vector<Edge> E;
  vector<int> dep;
  Dinic(int n = 0)
      : N(n), vc(vector<vector<int>>(N + 1)), dep(vector<int>(N + 1)) {}
  void add_edge(int a, int b, int c) {
    vc[a].push_back(E.size());
    E.push_back({a, b, c, c});
    vc[b].push_back(E.size());
    E.push_back({b, a, 0, c});
  }
  int Bfs(int s, int t) {
    fill(dep.begin(), dep.end(), -1);
    dep[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < (int)vc[v].size(); i++) {
        Edge e = E[vc[v][i]];
        if (e.f > 0 && dep[e.v2] == -1) {
          dep[e.v2] = dep[v] + 1;
          q.push(e.v2);
        }
      }
    }
    return dep[t];
  }
  int Dfs(int x, int df, int t) {
    if (x == t) return df;
    int res = 0;
    for (int i = 0; i < (int)vc[x].size(); i++) {
      Edge &e = E[vc[x][i]];
      if (e.f > 0 && dep[e.v2] == dep[x] + 1) {
        int f = Dfs(e.v2, min(df, e.f), t);
        e.f -= f;
        df -= f;
        res += f;
        E[vc[x][i] ^ 1].f += f;
        if (df == 0) return res;
      }
    }
    if (res == 0) dep[x] = -1;
    return res;
  }
  int Solve(int s, int t) {
    int flow = 0;
    while (Bfs(s, t) != -1) {
      flow += Dfs(s, 0x3f3f3f3f, t);
    }
    return flow;
  }
};
int main() {
  makePrime();
  scanf("%d", &N);
  int odd = 0, even = 0;
  int source = N, target = source + 1;
  Dinic d(N + 2);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (A[i] & 1) {
      d.add_edge(source, i, 2);
      odd++;
    } else {
      d.add_edge(i, target, 2);
      even++;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (isPrime[A[i] + A[j]]) {
        if (A[i] & 1) {
          d.add_edge(i, j, 1);
        } else {
          d.add_edge(j, i, 1);
        }
      }
    }
  }
  int flow = d.Solve(source, target);
  bool ans = flow == odd * 2 && even == odd;
  if (ans) {
    vector<int> ed[210];
    bool vis[210] = {0};
    for (auto e : d.E) {
      if (e.v1 != source && e.v1 != target && e.v2 != source &&
          e.v2 != target && (A[e.v1] & 1) && e.f == 0) {
        ed[e.v1].push_back(e.v2);
        ed[e.v2].push_back(e.v1);
      }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        int now = i;
        ans.push_back(vector<int>());
        while (!vis[now]) {
          vis[now] = true;
          ans.back().push_back(now);
          for (int j : ed[now]) {
            if (!vis[j]) {
              now = j;
              break;
            }
          }
        }
      }
    }
    printf("%d\n", (int)ans.size());
    for (auto c : ans) {
      printf("%d", (int)c.size());
      for (int x : c) {
        printf(" %d", x + 1);
      }
      puts("");
    }
  } else {
    printf("Impossible\n");
  }
  return 0;
}
