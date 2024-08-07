#include <bits/stdc++.h>
using namespace std;
struct ed {
  int to, nx;
  long long l;
} es[22020];
struct fed {
  int fr, en, cd;
  long long l;
} cg[111];
int s1, s2, f;
int hd[10101], ne, nc;
void ae(int fr, int to, int r, bool tp = 0, int l = 0) {
  es[ne].to = to;
  es[ne].l = r;
  es[ne].nx = hd[fr];
  if (tp) {
    cg[nc].fr = fr;
    cg[nc].en = ne;
    cg[nc].cd = 0;
    cg[nc++].l = l;
  }
  hd[fr] = ne++;
}
long long d1[10101], d2[10101];
struct dd {
  long long l;
  int n;
  dd(int nn, long long ll) : n(nn), l(ll) {}
  bool operator<(const dd &a) const { return l > a.l; }
};
bool out[10101];
void dijkstra(int s, long long *d) {
  priority_queue<dd> q;
  q.push(dd(s, 0));
  memset(d, 0x11, sizeof(d1));
  memset(out, 0, sizeof(out));
  while (!q.empty()) {
    int nw = q.top().n;
    int l = q.top().l;
    q.pop();
    if (out[nw]) continue;
    d[nw] = l;
    out[nw] = 1;
    for (int i = hd[nw]; i != -1; i = es[i].nx) {
      if (!out[es[i].to]) {
        q.push(dd(es[i].to, d[nw] + es[i].l));
      }
    }
  }
}
bool can(int eq) {
  dijkstra(s1, d1), dijkstra(s2, d2);
  while (1) {
    int flg = 0;
    for (int i = 0; i < nc; i++)
      if ((!cg[i].cd) && d1[cg[i].fr] < d2[cg[i].fr] + eq) {
        es[cg[i].en].l = cg[i].l;
        cg[i].cd = 1;
        flg = 1;
      }
    if (!flg) break;
    dijkstra(s1, d1), dijkstra(s2, d2);
  }
  return d1[f] < d2[f] + eq;
}
void prnt() {
  for (int i = 0; i < nc; i++) {
    printf("%d ", (int)es[cg[i].en].l);
  }
}
int main() {
  memset(hd, -1, sizeof(hd));
  int n, m, k;
  scanf("%d%d%d%d%d%d", &n, &m, &k, &s1, &s2, &f);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ae(a, b, c);
  }
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ae(a, b, d, 1, c);
  }
  if (can(0))
    printf("WIN\n"), prnt();
  else if (can(1))
    printf("DRAW\n"), prnt();
  else
    printf("LOSE");
}
