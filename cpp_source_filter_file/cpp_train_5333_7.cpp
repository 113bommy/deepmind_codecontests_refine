#include <bits/stdc++.h>
using namespace std;
const int N = 400 + 4;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n1, n2, m, r, b, rem, os, ot, s, t, p[N], dis[N], ans, left1, right1;
char c[N];
string color;
void no() {
  puts("-1");
  exit(0);
}
struct edge {
  int u, v, c, w;
  edge(int a = 0, int b = 0, int c = 0, int d = 0) {
    u = a;
    v = b;
    this->c = c;
    w = d;
  }
  void print() { cout << u << " " << v << " " << c << " " << w << endl; }
} e[8 * N];
void addEdge(int u, int v, int c, int w) {
  e[rem].u = u;
  e[rem].v = v;
  e[rem].c = c;
  e[rem++].w = w;
  e[rem].u = v;
  e[rem].v = u;
  e[rem].c = 0;
  e[rem++].w = -w;
}
bool FindPath() {
  dis[t] = (1LL << 31) - 1;
  p[t] = -1;
  for (int i = 0; i < s; i++) dis[i] = (1LL << 31) - 1, p[i] = -1;
  bool did = 1;
  while (did) {
    did = 0;
    for (int i = 0; i < rem; i++)
      if (e[i].c && p[e[i].u] != -1 && dis[e[i].u] + e[i].w < dis[e[i].v]) {
        did = 1;
        p[e[i].v] = i;
        dis[e[i].v] = dis[e[i].u] + e[i].w;
      }
  }
  return p[t] != -1;
}
long long MinCostMaxFlow() {
  long long flow = 0, cost = 0;
  while (FindPath()) {
    int mn = 1e9;
    for (int cur = t; cur != s; cur = e[p[cur]].u) mn = min(mn, e[p[cur]].c);
    for (int cur = t; cur != s; cur = e[p[cur]].u) {
      e[p[cur]].c -= mn;
      e[p[cur] ^ 1].c += m;
    }
    cost += dis[t] * mn;
    flow += mn;
  }
  if (flow < max(right1, left1)) no();
  return cost;
}
int main() {
  scanf("%d%d%d%d%d", &n1, &n2, &m, &r, &b);
  ot = (os = n1 + n2) + 1;
  t = (s = ot + 1) + 1;
  scanf(" %s", c);
  for (int i = 0; i < n1; i++)
    if (c[i] == 'R') {
      right1++;
      left1++;
      addEdge(s, i, 1, 0);
      addEdge(os, t, 1, 0);
      addEdge(os, i, 1e9, 0);
    } else if (c[i] == 'B') {
      left1++;
      right1++;
      addEdge(i, t, 1, 0);
      addEdge(s, ot, 1, 0);
      addEdge(i, ot, 1e9, 0);
    } else {
      addEdge(os, i, 1e9, 0);
      addEdge(i, ot, 1e9, 0);
    }
  scanf(" %s", c);
  for (int i = 0; i < n2; i++)
    if (c[i] == 'B') {
      right1++;
      left1++;
      addEdge(os, t, 1, 0);
      addEdge(s, i + n1, 1, 0);
      addEdge(os, i + n1, 1e9, 0);
    } else if (c[i] == 'R') {
      left1++;
      right1++;
      addEdge(s, ot, 1, 0);
      ;
      addEdge(i + n1, t, 1, 0);
      addEdge(i + n1, ot, 1e9, 0);
    } else {
      addEdge(os, i + n1, 1e9, 0);
      addEdge(i + n1, ot, 1e9, 0);
    }
  addEdge(ot, os, 1e9, 0);
  int st = rem;
  for (int i = 0, x, y; i < m; i++) {
    scanf("%d%d", &x, &y);
    --x;
    --y;
    addEdge(x, n1 + y, 1, r);
    addEdge(n1 + y, x, 1, b);
  }
  printf("%lld\n", MinCostMaxFlow());
  for (int i = st; i < rem; i += 4)
    if (!e[i].c)
      color += 'R';
    else if (!e[i + 2].c)
      color += 'B';
    else
      color += 'U';
  printf("%s", color.c_str());
}
