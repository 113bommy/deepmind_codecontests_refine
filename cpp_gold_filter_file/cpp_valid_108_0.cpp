#include <bits/stdc++.h>
template <typename _Tp>
void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 200005, inf = 0x3f3f3f3f;
struct BIT {
  long long c[N];
  void add(int x, long long C) {
    for (; x < N; x += ((x) & (-(x)))) c[x] += C;
  }
  long long ask(int x) {
    long long ans = 0;
    for (; x; x -= ((x) & (-(x)))) ans += c[x];
    return ans;
  }
} tr1, tr2;
struct DS {
  BIT a, b;
  inline void upd(int l, int r, int C) {
    tr1.add(l, C), tr1.add(r + 1, -C), tr2.add(l, 1LL * l * C),
        tr2.add(r + 1, -1LL * (r + 1) * C);
  }
  inline long long ask(int r) {
    return 1LL * (r + 1) * tr1.ask(r) - tr2.ask(r);
  }
  inline long long ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr;
int mx1[N << 2], mx2[N << 2], cnt[N << 2], tag[N << 2];
inline void pushup(int u) {
  int x = ((u) << 1), y = ((u) << 1 | 1);
  if (mx1[x] == mx1[y])
    mx1[u] = mx1[x], cnt[u] = cnt[x] + cnt[y],
    mx2[u] = std::max(mx2[x], mx2[y]);
  else if (mx1[x] > mx1[y])
    mx1[u] = mx1[x], cnt[u] = cnt[x], mx2[u] = std::max(mx2[x], mx1[y]);
  else
    mx1[u] = mx1[y], cnt[u] = cnt[y], mx2[u] = std::max(mx1[x], mx2[y]);
}
inline void upd(int u, int C) {
  if (C < mx1[u]) mx1[u] = C, tag[u] = C;
}
inline void pushdown(int u) {
  if (tag[u] < inf)
    upd(((u) << 1), tag[u]), upd(((u) << 1 | 1), tag[u]), tag[u] = inf;
}
void build(int l, int r, int u) {
  tag[u] = inf;
  if (l == r) return mx1[u] = l, cnt[u] = 1, void();
  int mid = (l + r) >> 1;
  build(l, mid, ((u) << 1)), build(mid + 1, r, ((u) << 1 | 1)), pushup(u);
}
void Update(int L, int R, int C, int l, int r, int u) {
  if (C >= mx1[u]) return;
  if (L <= l && r <= R && C > mx2[u])
    return tr.upd(C + 1, mx1[u], -cnt[u]), upd(u, C);
  int mid = (l + r) >> 1;
  pushdown(u);
  if (L <= mid) Update(L, R, C, l, mid, ((u) << 1));
  if (R > mid) Update(L, R, C, mid + 1, r, ((u) << 1 | 1));
  pushup(u);
}
void Modify(int pos, int C, int l, int r, int u) {
  if (l == r) {
    tr.upd(pos, mx1[u], -1), tr.upd(pos, C, 1);
    return mx1[u] = C, void();
  }
  int mid = (l + r) >> 1;
  pushdown(u);
  pos <= mid ? Modify(pos, C, l, mid, ((u) << 1))
             : Modify(pos, C, mid + 1, r, ((u) << 1 | 1));
  pushup(u);
}
int main() {
  int n, q, opt, x, y;
  read(n, q);
  for (int i = 1; i <= n; ++i) tr.upd(i, i, 1);
  build(1, n, 1);
  while (q--) {
    read(opt, x, y);
    if (opt == 1) {
      Modify(x, y, 1, n, 1);
      if (x > 1) Update(1, x - 1, x - 1, 1, n, 1);
    } else
      printf("%lld\n", tr.ask(x, y));
  }
  return 0;
}
