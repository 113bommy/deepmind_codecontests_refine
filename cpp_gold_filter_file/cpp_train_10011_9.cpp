#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 200200;
const long long inf = 1e18;
struct fc {
  int k;
  long long a;
};
int n, q;
fc o[maxn];
int a[maxn], b[maxn];
struct seg {
  static const int N = maxn << 2;
  fc max[N];
  long long rem[N], add[N];
  inline long long calc(const fc& x, const fc& y) {
    if (x.k >= y.k) return inf;
    return (x.a - y.a) / (y.k - x.k) + 1;
  }
  inline void update(int cur) {
    rem[cur] = std::min(rem[cur << 1], rem[cur << 1 | 1]);
    if (max[cur << 1].a > max[cur << 1 | 1].a) {
      max[cur] = max[cur << 1];
      rem[cur] = std::min(rem[cur], calc(max[cur << 1], max[cur << 1 | 1]));
    } else {
      max[cur] = max[cur << 1 | 1];
      rem[cur] = std::min(rem[cur], calc(max[cur << 1 | 1], max[cur << 1]));
    }
  }
  inline void put(int cur, long long v) {
    add[cur] += v;
    rem[cur] -= v;
    max[cur].a += max[cur].k * v;
  }
  inline void down(int cur) {
    put(cur << 1, add[cur]);
    put(cur << 1 | 1, add[cur]);
    add[cur] = 0;
  }
  inline void dfs(int cur) {
    if (rem[cur] > 0) return;
    down(cur);
    dfs(cur << 1), dfs(cur << 1 | 1);
    update(cur);
  }
  inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) {
      put(cur, v);
      if (rem[cur] <= 0) dfs(cur);
      return;
    }
    int mid = l + r >> 1;
    down(cur);
    if (ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
    if (mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
    update(cur);
  }
  inline long long qmax(int ql, int qr, int cur = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return max[cur].a;
    int mid = l + r >> 1;
    long long ret = -1e18;
    down(cur);
    if (ql <= mid) ret = std::max(ret, qmax(ql, qr, cur << 1, l, mid));
    if (mid < qr) ret = std::max(ret, qmax(ql, qr, cur << 1 | 1, mid + 1, r));
    return ret;
  }
  inline void build(int cur = 1, int l = 1, int r = n) {
    if (l == r) {
      max[cur] = o[l];
      rem[cur] = inf;
      return;
    }
    int mid = l + r >> 1;
    build(cur << 1, l, mid);
    build(cur << 1 | 1, mid + 1, r);
    update(cur);
  }
} seg0, seg1;
int head[maxn], next[maxn], size[maxn], dfn[maxn], tot;
inline void add(int fa, int x) { next[x] = head[fa], head[fa] = x; }
inline void dfs0(int x, int sa, int sb) {
  sa += a[x], sb += b[x];
  size[x] = 1;
  dfn[x] = ++tot;
  o[dfn[x]] = (fc){std::abs(sb), (long long)sa * std::abs(sb)};
  for (int i = head[x]; i; i = next[i]) {
    dfs0(i, sa, sb), size[x] += size[i];
  }
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = (2), iend = (n); i <= iend; ++i) {
    int f;
    cin >> f;
    add(f, i);
  }
  for (int i = (1), iend = (n); i <= iend; ++i) {
    cin >> a[i];
  }
  for (int i = (1), iend = (n); i <= iend; ++i) {
    cin >> b[i];
  }
  dfs0(1, 0, 0);
  seg0.build();
  for (int i = (1), iend = (n); i <= iend; ++i) {
    o[i].a = -o[i].a;
    o[i].k = -o[i].k;
  }
  seg1.build();
  for (int i = (1), iend = (q); i <= iend; ++i) {
    int opt, x, v;
    cin >> opt >> x;
    if (opt == 1) {
      cin >> v;
      seg0.upt(dfn[x], dfn[x] + size[x] - 1, v);
      seg1.upt(dfn[x], dfn[x] + size[x] - 1, v);
    } else {
      long long a0 = seg0.qmax(dfn[x], dfn[x] + size[x] - 1);
      long long a1 = seg1.qmax(dfn[x], dfn[x] + size[x] - 1);
      cout << std::max(a0, a1) << '\n';
    }
  }
}
