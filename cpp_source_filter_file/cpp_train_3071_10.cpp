#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
struct SegmentTree {
  int w[MAXN << 2], l[MAXN << 2], r[MAXN << 2];
  void build(int L, int R, int rt = 1) {
    l[rt] = L;
    r[rt] = R;
    w[rt] = 0;
    if (L + 1 == R) return;
    int mid = (L + R) >> 1;
    build(L, mid, rt << 1);
    build(mid, R, rt << 1 | 1);
  }
  void pushdown(int rt) {
    if (w[rt]) w[rt << 1] = w[rt << 1 | 1] = w[rt], w[rt] = 0;
  }
  void modify(int L, int R, int x, int rt = 1) {
    if (L >= r[rt] or l[rt] >= R) return;
    if (L <= l[rt] and r[rt] <= R) return void(w[rt] = x);
    pushdown(x);
    modify(L, R, x, rt << 1);
    modify(L, R, x, rt << 1 | 1);
  }
  int query(int pos, int rt = 1) {
    if (l[rt] + 1 == r[rt]) return w[rt];
    pushdown(rt);
    int mid = (l[rt] + r[rt]) >> 1;
    if (pos < mid)
      return query(pos, rt << 1);
    else
      return query(pos, rt << 1 | 1);
  }
} seg;
struct FenwickTree {
  long long sum[MAXN];
  void modify(int pos, int x) {
    while (pos < MAXN) sum[pos] += x, pos += (pos & (-pos));
  }
  long long qsum(int pos) {
    int ret = 0;
    while (pos) ret += sum[pos], pos -= (pos & (-pos));
    return ret;
  }
} bit;
struct Disjoint_Set_Union {
  int fa[MAXN];
  int findx(int x) { return x == fa[x] ? x : fa[x] = findx(fa[x]); }
  void merge(int x, int y) {
    if (findx(x) != findx(y)) fa[findx(x)] = findx(y);
  }
} dsu[2];
int n, q;
long long ret[MAXN];
struct Graph {
  vector<int> g[MAXN];
  int tot, st[MAXN], idx, ed[MAXN], sz[MAXN];
  vector<int> &operator[](int ID) { return g[ID]; }
  void dfs(int u) {
    sz[u] = u <= n ? 1 : 0;
    st[u] = ++idx;
    for (int v : g[u]) dfs(v), sz[u] += sz[v];
    ed[u] = idx;
  }
} G[2];
struct Event {
  int op, x, y, time, qid;
} Q[MAXN];
void init() {
  for (int i = 1; i <= (n << 1); i++) {
    dsu[0].fa[i] = dsu[1].fa[i] = i;
    G[0][i].clear();
    G[1][i].clear();
    bit.sum[i] = 0;
    G[0].sz[i] = G[1].sz[i] = 0;
  }
  G[0].tot = G[1].tot = n;
  G[0].idx = G[1].idx = 0;
  for (int i = 1; i <= q; i++) ret[i] = 0;
}
char buf[233];
int exc(char ch) {
  if (ch == 'U') return 1;
  if (ch == 'M') return 2;
  if (ch == 'A') return 3;
  if (ch == 'Z') return 4;
  if (ch == 'Q') return 5;
}
void solve() {
  scanf("%d %d", &n, &q);
  init();
  for (int i = 1; i <= q; i++) {
    scanf("%s", buf);
    Q[i].op = exc(buf[0]);
    assert(Q[i].op >= 1 and Q[i].op <= 5);
    Q[i].time = i;
    if (Q[i].op == 1) {
      scanf("%d %d", &Q[i].x, &Q[i].y);
      G[0].tot++;
      G[0][G[0].tot].push_back(dsu[0].findx(Q[i].x));
      G[0][G[0].tot].push_back(dsu[0].findx(Q[i].y));
      dsu[0].merge(Q[i].x, G[0].tot);
      dsu[0].merge(Q[i].y, G[0].tot);
    } else if (Q[i].op == 2) {
      scanf("%d %d", &Q[i].x, &Q[i].y);
      G[1].tot++;
      G[1][G[1].tot].push_back(dsu[1].findx(Q[i].x));
      G[1][G[1].tot].push_back(dsu[1].findx(Q[i].y));
      dsu[1].merge(Q[i].x, G[1].tot);
      dsu[1].merge(Q[i].y, G[1].tot);
    } else if (Q[i].op == 3) {
      scanf("%d", &Q[i].x);
      Q[i].x = dsu[0].findx(Q[i].x);
    } else if (Q[i].op == 4) {
      scanf("%d", &Q[i].x);
      Q[i].x = dsu[1].findx(Q[i].x);
    } else
      scanf("%d", &Q[i].x);
  }
  G[0].tot++;
  G[1].tot++;
  for (int i = 1; i < G[0].tot; i++)
    if (dsu[0].findx(i) == i) G[0][G[0].tot].push_back(i);
  for (int i = 1; i < G[1].tot; i++)
    if (dsu[1].findx(i) == i) G[1][G[1].tot].push_back(i);
  G[0].dfs(G[0].tot);
  G[1].dfs(G[1].tot);
  assert(G[0].tot <= (n << 1) and G[1].tot <= (n << 1));
  vector<Event> vec;
  seg.build(1, MAXN);
  int cnt_q = 0;
  for (int i = 1; i <= q; i++) {
    if (Q[i].op == 3)
      vec.push_back(Q[i]);
    else if (Q[i].op == 4)
      seg.modify(G[1].st[Q[i].x], G[1].ed[Q[i].x] + 1, i);
    else if (Q[i].op == 5) {
      Q[i].y = 1, Q[i].qid = ++cnt_q;
      vec.push_back(Q[i]);
      Q[i].y = -1;
      Q[i].time = seg.query(G[1].st[Q[i].x]);
      if (Q[i].time) vec.push_back(Q[i]);
    }
  }
  sort(vec.begin(), vec.end(),
       [&](const Event &A, const Event &B) { return A.time < B.time; });
  for (auto &qs : vec) {
    if (qs.op == 3) {
      int sz = G[0].sz[qs.x], st = G[0].st[qs.x], ed = G[0].ed[qs.x];
      bit.modify(st, sz);
      bit.modify(ed + 1, -sz);
    } else
      ret[qs.qid] += qs.y * bit.qsum(G[0].st[qs.x]);
  }
  for (int i = 1; i <= cnt_q; i++) printf("%lld\n", ret[i]);
}
int main() {
  solve();
  return 0;
}
