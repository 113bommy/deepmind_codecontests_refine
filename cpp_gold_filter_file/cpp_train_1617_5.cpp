#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct edge {
  int to, next;
} e[2 * N];
struct segtree {
  int lnum, rnum, lch, rch, delta;
  bitset<1000> data;
} tree[2 * N];
int n, m, times, cnt, a[N], dfn[N][2], st[N], head[N];
bitset<1000> all, ans;
void push(int k, int x, int y) {
  e[k].to = y;
  e[k].next = head[x];
  head[x] = k;
}
bool prime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void dfs(int k) {
  st[++times] = k;
  dfn[k][0] = times;
  int p = head[k];
  while (p) {
    if (!dfn[e[p].to][0]) dfs(e[p].to);
    p = e[p].next;
  }
  dfn[k][1] = times;
}
void build(int k, int l, int r) {
  tree[k].lnum = l;
  tree[k].rnum = r;
  tree[k].delta = 0;
  if (l == r) {
    tree[k].data[a[st[l]] % m] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  tree[k].lch = ++cnt;
  build(cnt, l, mid);
  tree[k].rch = ++cnt;
  build(cnt, mid + 1, r);
  tree[k].data = tree[tree[k].lch].data | tree[tree[k].rch].data;
}
void update(int k, int d) {
  tree[k].delta = (tree[k].delta + d) % m;
  tree[k].data = ((tree[k].data << d) & all) | (tree[k].data >> (m - d));
}
void pushdown(int k) {
  if (tree[k].delta) {
    update(tree[k].lch, tree[k].delta);
    update(tree[k].rch, tree[k].delta);
    tree[k].delta = 0;
  }
}
void change(int k, int l, int r, int d) {
  if (l <= tree[k].lnum && r >= tree[k].rnum) {
    update(k, d);
    return;
  }
  pushdown(k);
  if (l < tree[tree[k].rch].lnum) change(tree[k].lch, l, r, d);
  if (r > tree[tree[k].lch].rnum) change(tree[k].rch, l, r, d);
  tree[k].data = tree[tree[k].lch].data | tree[tree[k].rch].data;
}
void query(int k, int l, int r) {
  if (l <= tree[k].lnum && r >= tree[k].rnum) {
    ans = ans | tree[k].data;
    return;
  }
  pushdown(k);
  if (l < tree[tree[k].rch].lnum) query(tree[k].lch, l, r);
  if (r > tree[tree[k].lch].rnum) query(tree[k].rch, l, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    push(2 * i - 1, x, y);
    push(2 * i, y, x);
  }
  dfs(1);
  cnt = 0;
  build(0, 1, n);
  bitset<1000> pr;
  for (int i = 0; i < m; i++) all[i] = 1;
  for (int i = 2; i < m; i++)
    if (prime(i)) pr[i] = 1;
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      scanf("%d", &y);
      change(0, dfn[x][0], dfn[x][1], y % m);
    } else {
      ans.reset();
      query(0, dfn[x][0], dfn[x][1]);
      ans = ans & pr;
      printf("%d\n", ans.count());
    }
  }
  return 0;
}
