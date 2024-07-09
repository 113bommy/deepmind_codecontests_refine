#include <bits/stdc++.h>
const int lim = 2e5;
int n, q, a[200005], cnt[200005], x, y;
std::set<int> S[200005];
struct data {
  int l, r, min, ans;
};
struct mikeMirzayanov {
  int max[200005 << 2];
  void modify(int l, int r, int p, int v, int rt) {
    if (l == r) {
      max[rt] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      modify(l, mid, p, v, rt << 1);
    else
      modify(mid + 1, r, p, v, rt << 1 | 1);
    max[rt] = std::max(max[rt << 1], max[rt << 1 | 1]);
  }
  int query(int l, int r, int L, int R, int rt) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) return max[rt];
    return std::max(query(l, r, L, (L + R) >> 1, rt << 1),
                    query(l, r, ((L + R) >> 1) + 1, R, rt << 1 | 1));
  }
} W;
data merge(data a, data b) {
  if (a.min > b.min) std::swap(a, b);
  if (a.min != b.min)
    return a;
  else
    return data(
        {a.l, b.r, a.min, W.query(a.l + 1, b.r, 1, n, 1) + a.ans + b.ans});
}
struct segmentTree {
  data sum[200005 << 2];
  int tag[200005 << 2];
  void update(int x) { sum[x] = merge(sum[x << 1], sum[x << 1 | 1]); }
  void give_tag(int x, int y) {
    sum[x].min += y;
    tag[x] += y;
  }
  void pushdown(int x) {
    if (!tag[x]) return;
    give_tag(x << 1, tag[x]);
    give_tag(x << 1 | 1, tag[x]);
    tag[x] = 0;
  }
  void build(int l, int r, int rt) {
    if (l == r) {
      sum[rt] = data({l, l, 0, 0});
      return;
    }
    build(l, (l + r) >> 1, rt << 1);
    build(((l + r) >> 1) + 1, r, rt << 1 | 1);
    update(rt);
  }
  void add(int l, int r, int L, int R, int v, int rt) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
      give_tag(rt, v);
      return;
    }
    pushdown(rt);
    add(l, r, L, (L + R) >> 1, v, rt << 1);
    add(l, r, ((L + R) >> 1) + 1, R, v, rt << 1 | 1);
    update(rt);
  }
  void dfs(int l, int r, int rt) {
    if (l == r) return;
    pushdown(rt);
    dfs(l, (l + r) >> 1, rt << 1);
    dfs(((l + r) >> 1) + 1, r, rt << 1 | 1);
    update(rt);
  }
  void visit(int l, int r, int L, int R, int rt) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) return;
    pushdown(rt);
    visit(l, r, L, (L + R) >> 1, rt << 1);
    visit(l, r, ((L + R) >> 1) + 1, R, rt << 1 | 1);
    update(rt);
  }
} A;
void inc(int x) {
  if (S[x].empty()) return;
  W.modify(1, n, *S[x].begin(), S[x].size(), 1);
  if (S[x].size() > 1) A.add(*S[x].begin(), *S[x].rbegin() - 1, 0, n, 1, 1);
}
void dec(int x) {
  if (S[x].empty()) return;
  W.modify(1, n, *S[x].begin(), 0, 1);
  if (S[x].size() > 1) A.add(*S[x].begin(), *S[x].rbegin() - 1, 0, n, -1, 1);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    S[a[i]].insert(i);
  }
  A.build(0, n, 1);
  for (int i = 1; i <= lim; ++i) inc(i);
  A.dfs(0, n, 1);
  printf("%d\n", n - A.sum[1].ans);
  while (q--) {
    scanf("%d%d", &x, &y);
    dec(a[x]);
    dec(y);
    int last = a[x];
    S[a[x]].erase(x);
    a[x] = y;
    S[y].insert(x);
    inc(last);
    inc(y);
    A.visit(*S[y].begin(), *S[y].rbegin(), 1, n, 1);
    if (S[last].size()) A.visit(*S[last].begin(), *S[last].rbegin(), 0, n, 1);
    printf("%d\n", n - A.sum[1].ans);
  }
  return 0;
}
