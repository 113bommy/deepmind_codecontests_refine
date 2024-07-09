#include <bits/stdc++.h>
using namespace std;
template <class T>
string tostring(T x) {
  ostringstream out;
  out << x;
  return out.str();
}
long long toint(string s) {
  istringstream in(s);
  long long x;
  in >> x;
  return x;
}
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int kx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int ky[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int n, m, q;
struct SegmentTree {
  struct Node {
    int maxL, minR;
  };
  vector<Node> nodes;
  int n;
  SegmentTree(int n) {
    this->n = n;
    nodes.resize(n * 4);
  }
  Node merge(Node a, Node b) {
    return Node({max(a.maxL, b.maxL), min(a.minR, b.minR)});
  }
  void _set(int idx, int l, int r, int pos, int maxL, int minR) {
    if (l == r) {
      nodes[idx] = Node({maxL, minR});
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
      _set(idx * 2 + 1, l, mid, pos, maxL, minR);
    else
      _set(idx * 2 + 2, mid + 1, r, pos, maxL, minR);
    nodes[idx] = merge(nodes[idx * 2 + 1], nodes[idx * 2 + 2]);
  }
  void set(int pos, int maxL, int minR) { _set(0, 0, n - 1, pos, maxL, minR); }
  Node _query(int idx, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) return nodes[idx];
    int mid = (l + r) / 2;
    if (qr <= mid)
      return _query(idx * 2 + 1, l, mid, ql, qr);
    else if (ql > mid)
      return _query(idx * 2 + 2, mid + 1, r, ql, qr);
    else
      return merge(_query(idx * 2 + 1, l, mid, ql, mid),
                   _query(idx * 2 + 2, mid + 1, r, mid + 1, qr));
  }
  Node query(int l, int r) { return _query(0, 0, n - 1, l, r); }
};
void solveOne() {
  cin >> n >> m >> q;
  SegmentTree tree(n * 2);
  for (int i = 0; i < 2 * n; i++) tree.set(i, -1, 1 << 30);
  vector<set<int>> setL(n * 2);
  vector<set<int>> setR(n * 2);
  map<pair<int, int>, int> cell;
  set<pair<int, int>> bad;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int c = cell[make_pair(x, y)];
    cell[make_pair(x, y)] = c ^ 1;
    bool ok = false;
    if (x % 2 == 0) {
      if (c == 0)
        setR[x].insert(y);
      else
        setR[x].erase(y);
      int l = setL[x].size() == 0 ? -1 : *setL[x].rbegin();
      int r = setR[x].size() == 0 ? 1 << 30 : *setR[x].begin();
      tree.set(x, l, r);
      SegmentTree::Node node = tree.query(x, 2 * n - 1);
      if (node.maxL < y)
        bad.erase(make_pair(x, y));
      else
        bad.insert(make_pair(x, y));
    } else {
      if (c == 0)
        setL[x].insert(y);
      else
        setL[x].erase(y);
      int l = setL[x].size() == 0 ? -1 : *setL[x].rbegin();
      int r = setR[x].size() == 0 ? 1 << 30 : *setR[x].begin();
      tree.set(x, l, r);
      SegmentTree::Node node = tree.query(0, x);
      if (node.minR > y)
        bad.erase(make_pair(x, y));
      else
        bad.insert(make_pair(x, y));
    }
    cout << (bad.size() == 0 ? "YES" : "NO") << endl;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    solveOne();
  }
  return 0;
}
