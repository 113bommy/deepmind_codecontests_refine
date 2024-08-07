#include <bits/stdc++.h>
using namespace std;
int const INF = 2e9;
int const NONE = -1232;
struct Query {
  int type;
  int l, r, x;
  int k, d;
};
int extract(vector<int> &tree, int sz, int v) {
  int ret = INF;
  for (v += sz; v; v /= 2) ret = min(ret, tree[v]);
  return ret;
}
void update(vector<int> &tree, int sz, int l, int r, int val) {
  for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
    if (l & 1) tree[l] = min(tree[l], val), ++l;
    if (r & 1) --r, tree[r] = min(tree[r], val);
  }
}
void modify(vector<int> &tree, int sz, int v, int x) {
  tree[v += sz] = x;
  for (v /= 2; v; v /= 2) tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
int get_max(vector<int> &tree, int sz, int l, int r) {
  int ret = -INF;
  for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
    if (l & 1) ret = max(ret, tree[l++]);
    if (r & 1) ret = max(ret, tree[--r]);
  }
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int sz = 1;
  while (sz < n) sz *= 2;
  vector<int> tree(sz * 2 + 1, INF);
  vector<int> bound(n, NONE);
  vector<Query> qs(m);
  for (auto &q : qs) {
    scanf("%d", &q.type);
    if (q.type == 2) {
      scanf("%d%d", &q.k, &q.d);
      --q.k;
      if (bound[q.k] == NONE) bound[q.k] = extract(tree, sz, q.k);
    } else {
      scanf("%d%d%d", &q.l, &q.r, &q.x);
      --q.l;
      update(tree, sz, q.l, q.r, q.x);
    }
  }
  for (int i = 0; i < n; ++i)
    if (bound[i] == NONE) bound[i] = extract(tree, sz, i);
  fill(tree.begin(), tree.end(), -INF);
  copy(bound.begin(), bound.end(), next(tree.begin(), sz));
  for (int i = sz - 1; i; --i) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
  for (auto &q : qs) {
    if (q.type == 2)
      modify(tree, sz, q.k, q.d);
    else if (get_max(tree, sz, q.l, q.r) != q.x) {
      cout << "NO\n";
      return 0;
    }
  }
  vector<int> infs;
  set<int> was;
  for (int i = 0; i < n; ++i) {
    if (bound[i] == INF)
      infs.push_back(i);
    else if (was.count(bound[i])) {
      int two = 1;
      while (two <= bound[i]) two *= 2;
      two /= 2;
      bound[i] = max(0, two - 1);
    } else
      was.insert(bound[i]);
  }
  if (infs.size() >= 2u) {
    for (int i : infs) bound[i] = 1 << 29;
    bound[infs.back()] = (1 << 29) - 1;
  } else if (infs.size() == 1u) {
    int cuteness = 0;
    for (int b : bound)
      if (b != INF) cuteness |= b;
    int val = 0;
    for (int x = 1 << 29; x > 0; x /= 2)
      if ((cuteness & x) == 0 && val + x <= 1000000000) val += x;
    bound[infs[0]] = val;
  }
  cout << "YES\n";
  for (int b : bound) cout << b << ' ';
  cout << '\n';
}
