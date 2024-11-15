#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;
template <typename T>
void ckmin(T &a, const T &b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T &a, const T &b) {
  a = max(a, b);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2> &p);
template <class T>
void re(vector<T> &a);
template <class T, size_t SZ>
void re(array<T, SZ> &a);
template <class T>
void re(T &x) {
  cin >> x;
}
void re(double &x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2> &p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T> &a) {
  for (int i = 0; i < int((a).size()); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ> &a) {
  for (int i = 0; i < SZ; i++) re(a[i]);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <typename T>
struct is_outputtable {
  template <typename C>
  static constexpr decltype(declval<ostream &>() << declval<const C &>(),
                            bool())
  test(int) {
    return true;
  }
  template <typename C>
  static constexpr bool test(...) {
    return false;
  }
  static constexpr bool value = test<T>(int());
};
template <
    class T, typename V = decltype(declval<const T &>().begin()),
    typename S = typename enable_if<!is_outputtable<T>::value, bool>::type>
void pr(const T &x);
template <class T,
          typename V = decltype(declval<ostream &>() << declval<const T &>())>
void pr(const T &x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x);
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  pr(first);
  pr(rest...);
}
template <class T, bool pretty = true>
void prContain(const T &x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T &x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T1, class T2>
void pr(const pair<T1, T2> &x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T, typename V, typename S>
void pr(const T &x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg &first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg &first, const Args &...rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __algorithm {
template <typename T>
void dedup(vector<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
template <typename T>
typename vector<T>::const_iterator find(const vector<T> &v, const T &x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(const vector<T> &v, const T &x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename I>
struct _reversed_struct {
  I &v_;
  explicit _reversed_struct(I &v) : v_{v} {}
  typename I::reverse_iterator begin() const { return v_.rbegin(); }
  typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I>
_reversed_struct<I> reversed(I &v) {
  return _reversed_struct<I>(v);
}
}  // namespace __algorithm
using namespace __algorithm;
namespace __io {
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
}
}  // namespace __io
using namespace __io;
struct edge {
  int u_xor_v;
  edge() : u_xor_v(0) {}
  edge(int _u_xor_v) : u_xor_v(_u_xor_v) {}
  int get_nbr(int u) const {
    assert(u_xor_v);
    return u ^ u_xor_v;
  }
};
template <typename Data>
struct edge_with_data : edge {
  Data data;
  edge_with_data() : edge() {}
  edge_with_data(int _u_xor_v, Data _data) : edge(_u_xor_v), data(_data) {}
};
enum TreeInputFormat { EDGE_LIST, PARENT_LIST };
template <typename Edge>
struct tree {
  int V, root;
  std::vector<std::vector<Edge>> neighbors;
  std::vector<int> parent, depth, subtree_size, preorder, preorder_index;
  tree() : V(0), root(-1) {}
  tree(int _V, int _root) : V(_V), root(_root), neighbors(V) {}
  void add_edge(int u, int v, Edge e = {}) {
    assert(0 <= u && u < V && 0 <= v && v < V);
    e.u_xor_v = u ^ v;
    neighbors[u].push_back(e);
    neighbors[v].push_back(e);
  }
  const Edge &parent_edge(int u) const {
    assert(u != root);
    return neighbors[u].front();
  }
  template <typename Function>
  void for_each_child(int u, Function fn) const {
    for (int i = u != root; i < int(neighbors[u].size()); i++)
      fn(neighbors[u][i]);
  }
  static void DefaultEdgeDataReader(__attribute((unused)) Edge &e) {}
  template <typename EdgeDataReader = void (*)(Edge &)>
  friend void re(tree &t, TreeInputFormat Format, int FirstIndex,
                 EdgeDataReader read = DefaultEdgeDataReader) {
    assert(t.V > 0);
    for (int i = 0; i < t.V - 1; i++) {
      int u, v;
      std::cin >> u, u -= FirstIndex;
      if (Format == PARENT_LIST)
        v = i + 1;
      else
        std::cin >> v, v -= FirstIndex;
      Edge e;
      read(e);
      t.add_edge(u, v, e);
    }
    t.init();
  }
  void reroot(int _root) {
    root = _root;
    init();
  }
  void init() {
    parent.resize(V), depth.resize(V), subtree_size.resize(V),
        preorder_index.resize(V);
    parent[root] = -1;
    depth[root] = 0;
    traverse(root);
    for (int u = 0; u < V; u++) {
      sort(neighbors[u].begin(), neighbors[u].end(),
           [&](const Edge &a, const Edge &b) {
             return subtree_size[a.get_nbr(u)] > subtree_size[b.get_nbr(u)];
           });
    }
    preorder.clear();
    build_preorder(root);
  }
  void traverse(int u) {
    subtree_size[u] = 1;
    for (Edge e : neighbors[u]) {
      int v = e.get_nbr(u);
      if (v == parent[u]) continue;
      parent[v] = u;
      depth[v] = depth[u] + 1;
      traverse(v);
      subtree_size[u] += subtree_size[v];
    }
  }
  void build_preorder(int u) {
    preorder_index[u] = preorder.size();
    preorder.push_back(u);
    for_each_child(u, [&](Edge e) { build_preorder(e.get_nbr(u)); });
  }
  static void DefaultEdgeDataWriter(__attribute((unused)) Edge &e) {}
  template <typename EdgeDataWriter = void (*)(Edge &)>
  friend void pr(const tree &t, EdgeDataWriter write = DefaultEdgeDataWriter) {
    std::cout << "{V=" << t.V << " root=" << t.root << " |";
    for (int u = 0; u < t.V; u++) {
      std::cout << " " << u << "--{";
      t.for_each_child(u, [&](Edge e) {
        std::cout << "(ch=" << e.get_nbr(u);
        write(e);
        std::cout << ")";
      });
      std::cout << "}";
    }
    std::cout << "}";
  }
};
using E = edge;
int main() {
  setIO();
  int n;
  re(n);
  tree<E> tr(n, 0);
  re(tr, EDGE_LIST, 1);
  vector<ll> down(n);
  vector<ll> up(n);
  vector<ll> combined(n);
  for (int i : reversed(tr.preorder)) {
    int p = tr.parent[i];
    down[i] += tr.subtree_size[i];
    if (p == -1) continue;
    down[p] += down[i];
  }
  for (int r : tr.preorder) {
    vi children;
    for (auto e : tr.neighbors[r]) {
      int c = e.get_nbr(r);
      if (c != tr.parent[r]) children.push_back(c);
    }
    vi prefix(1);
    for (int c : children) prefix.push_back(prefix.back() + down[c]);
    vi suffix(1);
    for (int c : reversed(children)) suffix.push_back(suffix.back() + down[c]);
    for (int i = 0; i < int((children).size()); i++) {
      int c = children[i];
      up[c] += up[r];
      up[c] += prefix[i] + suffix[int((children).size()) - 1 - i];
      up[c] += n - tr.subtree_size[c];
    }
  }
  for (int i = 0; i < n; i++)
    combined[i] = up[i] + (down[i] - tr.subtree_size[i]) + n;
  ll ans = *max_element((combined).begin(), (combined).end());
  ps(ans);
  return 0;
}
