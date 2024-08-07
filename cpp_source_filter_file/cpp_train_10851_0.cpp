#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y, next, f, c;
};
const int INF = 1000000, maxn = 253 << 1, maxm = maxn * maxn;
int n, m, num, s, ss, t;
typedef int node[maxn];
char val[maxn];
node a, head, d, p;
bool vis[maxn];
edge e[maxm];
inline int cost(int k) {
  int res = 0;
  while (k) {
    res += (k & 1);
    k >>= 1;
  }
  return res;
}
inline void add(int a, int b, int c, int d) {
  num++;
  e[num].next = head[a];
  head[a] = num;
  e[num].x = a;
  e[num].y = b;
  e[num].f = c;
  e[num].c = d;
  num++;
  e[num].next = head[b];
  head[b] = num;
  e[num].x = b;
  e[num].y = a;
  e[num].f = 0;
  e[num].c = -d;
}
inline int slove() {
  int ans = 0;
  while (true) {
    memset(d, 32, sizeof d);
    d[s] = 0;
    memset(vis, 0, sizeof vis);
    queue<int> Q;
    Q.push(s);
    vis[s] = true;
    while (!Q.empty()) {
      int i = Q.front();
      vis[i] = false;
      Q.pop();
      for (int temp = head[i]; temp >= 0; temp = e[temp].next) {
        int j = e[temp].y;
        if (e[temp].f && d[j] > d[i] + e[temp].c) {
          d[j] = d[i] + e[temp].c;
          p[j] = temp;
          if (!vis[j]) {
            vis[j] = true;
            Q.push(j);
          }
        }
      }
    }
    if (d[t] < INF) {
      int i = t, cost = 0;
      while (i != s) {
        e[p[i]].f--;
        e[p[i] ^ 1].f++;
        cost += e[p[i]].c;
        i = e[p[i]].x;
      }
      ans += cost;
    } else
      break;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  s = 2 * n, ss = 2 * n + 1, t = 2 * n + 2;
  memset(head, -1, sizeof head);
  num = -1;
  add(s, ss, m, 0);
  add(s, t, m, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    add(ss, i, 1, cost(a[i]));
    add(i, i + n, 1, -INF);
    for (int j = 0; j < i; j++) add(j + n, i, 1, cost(a[i]) * (a[i] != a[j]));
    add(i + n, t, 1, 0);
  }
  int ans = slove() + INF * n, w = n;
  for (int i = 0; i < n; i++)
    for (int temp = head[i]; temp >= 0; temp = e[temp].next)
      w += (e[temp].f && e[temp].c != 0);
  printf("%d %d\n", w, ans);
  val[ss] = 'a';
  for (int i = 0; i < n; i++) {
    for (int temp = head[i]; temp >= 0; temp = e[temp].next)
      if (e[temp].f) {
        int j = e[temp].y;
        if (e[temp].c != 0) printf("%c=%d\n", val[j], a[i]);
        val[i + n] = val[j];
        if (j == ss) val[j]++;
      }
    printf("print(%c)\n", val[i + n]);
  }
  return 0;
}
