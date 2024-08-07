#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
struct edge {
 public:
  int x, y, f, p, c;
} e[10000];
int st[10000], tot = 1, n, m, S, T, all, unravel, K;
void add(int a, int b, int c, int d) {
  e[++tot].x = a;
  e[tot].y = b;
  e[tot].f = c;
  e[tot].p = st[a];
  e[tot].c = d;
  st[a] = tot;
}
void ad(int a, int b, int c, int d) {
  add(a, b, c, d);
  add(b, a, 0, -d);
}
bool vs[10000];
int dis[10000];
int fr[10000];
bool SPFA() {
  queue<int> q;
  q.push(S);
  int u, v;
  for (int i = 1; i <= all; ++i) dis[i] = INF;
  dis[S] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    vs[u] = 0;
    for (int i = st[u]; i; i = e[i].p)
      if (dis[v = e[i].y] > dis[u] + e[i].c && e[i].f > 0) {
        if (!vs[v]) {
          vs[v] = 1;
          q.push(v);
        }
        dis[v] = dis[u] + e[i].c;
        fr[v] = i;
      }
  }
  return dis[T] != INF;
}
void MAXFLOW() {
  int cur, flo, tmp;
  while (SPFA()) {
    cur = T;
    flo = INF;
    while (cur != S) {
      tmp = fr[cur];
      flo = min(flo, e[tmp].f);
      cur = e[tmp].x;
    }
    cur = T;
    while (cur != S) {
      tmp = fr[cur];
      unravel += e[tmp].c * flo;
      e[tmp].f -= flo;
      e[tmp ^ 1].f += flo;
      cur = e[tmp].x;
    }
  }
}
void open() {
  freopen("tt.in", "r", stdin);
  freopen("tt.out", "w", stdout);
}
char s1[3000000], s2[3000000];
inline int id(char x) {
  if (x >= 'a' && x <= 'z')
    return x - 'a' + 1;
  else
    return x - 'A' + 27;
}
int w[200][200];
char lovelive[200];
int main() {
  scanf("%d%d", &n, &K);
  scanf("%s%s", s1 + 1, s2 + 1);
  all = (K << 1) + 2;
  S = (K << 1) + 1;
  T = (K << 1) + 2;
  for (int i = 1, x1, x2; i <= n; ++i) {
    x1 = id(s1[i]);
    x2 = id(s2[i]);
    --w[x1][x2];
  }
  for (int i = 1; i <= K; ++i) {
    ad(S, i, 1, 0);
    ad(i + K, T, 1, 0);
  }
  for (int i = 1; i <= K; ++i)
    for (int j = 1; j <= K; ++j) ad(i, K + j, 1, w[i][j]);
  MAXFLOW();
  cout << -unravel << endl;
  for (int i = 1; i <= K; ++i) {
    for (int j = st[i]; j; j = e[j].p)
      if (e[j].f == 0) {
        if (e[j].y - K < 27)
          lovelive[i] = e[j].y - K - 1 + 'a';
        else
          lovelive[i] = e[j].y - K - 27 + 'A';
        break;
      }
  }
  printf("%s\n", lovelive + 1);
  return 0;
}
