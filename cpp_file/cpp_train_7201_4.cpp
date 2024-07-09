#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
  return os << "(" << x.first << "," << x.second << ")";
}
struct SegTree {
  struct Node {
    long double mn = 0;
    long double prop = 0;
    void apply(int s, int e, long double v) {
      mn += v;
      prop += v;
    }
  };
  inline Node combine(const Node& a, const Node& b) {
    Node res;
    res.mn = min(a.mn, b.mn);
    return res;
  }
  inline void push(int sn, int s, int e) {
    if (tree[sn].prop != 0) {
      int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
      tree[lsn].apply(s, m, tree[sn].prop);
      tree[rsn].apply(m + 1, e, tree[sn].prop);
      tree[sn].prop = 0;
    }
  }
  int start, end;
  vector<Node> tree;
  void build(int sn, int s, int e) {
    if (s == e) {
      return;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    build(lsn, s, m);
    build(rsn, m + 1, e);
    tree[sn] = combine(tree[lsn], tree[rsn]);
  }
  template <typename... T>
  void update(int sn, int s, int e, int qs, int qe, const T&... v) {
    if (qs <= s && e <= qe) {
      tree[sn].apply(s, e, v...);
      return;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qs <= m) update(lsn, s, m, qs, qe, v...);
    if (qe > m) update(rsn, m + 1, e, qs, qe, v...);
    tree[sn] = combine(tree[lsn], tree[rsn]);
  }
  Node query(int sn, int s, int e, int qs, int qe) {
    if (qs <= s && e <= qe) return tree[sn];
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qe <= m) return query(lsn, s, m, qs, qe);
    if (qs > m) return query(rsn, m + 1, e, qs, qe);
    return combine(query(lsn, s, m, qs, qe), query(rsn, m + 1, e, qs, qe));
  }
  void query(int sn, int s, int e, int qs, int qe,
             const function<void(Node&, int, int)>& f) {
    if (qs <= s && e <= qe) return f(tree[sn], s, e);
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qs <= m) query(lsn, s, m, qs, qe, f);
    if (qe > m) query(rsn, m + 1, e, qs, qe, f);
  }
  SegTree(int n) : SegTree(0, n - 1) {}
  SegTree(int _start, int _end) : start(_start), end(_end) {
    int n = end - start + 1;
    int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
    tree.resize(maxs);
    build(1, start, end);
  }
  template <typename T>
  SegTree(vector<T>& v) {
    int n = v.size();
    int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
    tree.resize(maxs);
    start = 0;
    end = n - 1;
    build(1, start, end, v);
  }
  Node query(int qs, int qe) { return query(1, start, end, qs, qe); }
  Node query(int p) { return query(1, start, end, p, p); }
  void query(int qs, int qe, const function<void(Node&, int, int)>& f) {
    if (qs > qe) return;
    query(1, start, end, qs, qe, f);
  }
  template <typename... T>
  void update(int qs, int qe, const T&... v) {
    update(1, start, end, qs, qe, v...);
  }
};
int main() {
  int n, L;
  scanf("%d%d", &n, &L);
  vector<int> x(n + 1), y(n + 1);
  vector<pair<int, long long>> segs;
  const long long ONE = 1e9;
  for (int i = 1; i <= n; ++i) {
    long double s;
    scanf("%d%d%Lf", &x[i], &y[i], &s);
    long long d = llround(s * 1e9);
    if (x[i] > y[i - 1]) {
      segs.push_back({x[i] - y[i - 1], 0});
    }
    segs.push_back({y[i] - x[i], d});
  }
  if (y[n] != L) segs.push_back({L - y[n], 0});
  int m = segs.size();
  vector<int> ids(m);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(),
       [&](int a, int b) { return segs[a].second < segs[b].second; });
  vector<long double> amt(m);
  long double ans = 0;
  SegTree st(m);
  for (int i = 0; i < m; ++i) {
    long double vi;
    if (!segs[i].second) {
      vi = 1;
      amt[i] = segs[i].first / (vi + 1);
    } else {
      vi = (long double)segs[i].second / ONE;
      amt[i] = segs[i].first / vi + segs[i].first / (vi + 2);
      st.update(i, m - 1, segs[i].first / vi);
    }
    ans += segs[i].first / vi;
  }
  for (int i : ids) {
    auto x = st.query(i, m - 1);
    long double e = x.mn;
    e = min(e, amt[i]);
    long double vi = (long double)(segs[i].second + ONE) / ONE;
    ans -= e / vi;
    st.update(i, m - 1, -e);
  }
  printf("%.12Lf\n", ans);
}
