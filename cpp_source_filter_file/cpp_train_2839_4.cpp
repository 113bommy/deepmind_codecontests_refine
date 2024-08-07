#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename Monoid, typename F>
struct SegmentTree {
  int sz;
  vector<Monoid> seg;
  const F f;
  const Monoid M1;
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  void set(int k, const Monoid &x) { seg[k + sz] = x; }
  void build() {
    for (int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  Monoid operator[](const int &k) const { return seg[k + sz]; }
  template <typename C>
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while (a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  template <typename C>
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        Monoid nxt = f(L, seg[a]);
        if (check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  template <typename C>
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        Monoid nxt = f(seg[--b], R);
        if (check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
template <typename Monoid, typename F>
SegmentTree<Monoid, F> get_segment_tree(int N, const F &f, const Monoid &M1) {
  return {N, f, M1};
}
ll maxBC(ll diff, ll startNum) {
  ll sum = diff + startNum;
  ll ans = sum / 2;
  return max(sum - ans, ans);
}
int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < (N); ++i) {
    cin >> a[i];
  }
  auto seg = get_segment_tree(
      N + 5, [](ll a, ll b) { return (max(a, 0ll) + max(b, 0ll)); }, 0);
  for (int i = 0; i < (N); ++i) {
    if (i == 0) {
      seg.set(i, 0);
    }
    seg.set(i, a[i] - a[i - 1]);
  }
  seg.build();
  int Q;
  cin >> Q;
  cout << maxBC(seg.query(0, N), a[0]) << "\n";
  for (int q = 0; q < (Q); ++q) {
    ll l, r, x;
    cin >> l >> r >> x;
    --l;
    --r;
    if (l == 0) {
      a[0] += x;
    } else {
      seg.update(l, seg[l] + x);
    }
    seg.update(r + 1, seg[r + 1] - x);
    cout << maxBC(seg.query(0, N), a[0]) << "\n";
  }
  return 0;
}
