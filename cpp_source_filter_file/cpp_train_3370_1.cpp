#include <bits/stdc++.h>
using namespace std;
struct BIT {
  int n;
  int tree[101111];
  void setsize(int n) { this->n = n; }
  int shift(int x) { return x & (-x); }
  void update(int index, int val) {
    while (index <= n) {
      tree[index] += 1ll * val;
      index += shift(index);
    }
  }
  int getans(int index) {
    int ret = 0;
    while (index > 0) {
      ret += tree[index];
      index -= shift(index);
    }
    return ret;
  }
  int query(int l, int r) { return getans(r) - getans(l - 1); }
};
struct people {
  long long ti;
  int from, to, id;
  bool operator<(people other) const { return ti < other.ti; }
};
int m;
int T = 0;
int level = 1;
people p[101111];
long long ans[101111];
BIT waiting, leaving;
set<int> ins;
vector<people> in[101111];
set<int> ots;
vector<people> out[101111];
int cnt = 0;
int getdirection() {
  int nd = waiting.query(1, level - 1) + leaving.query(1, level - 1);
  int np = waiting.query(level + 1, m) + leaving.query(level + 1, m);
  return np >= nd;
}
bool stay() { return (waiting.query(1, m) + leaving.query(1, m)) == 0; }
int main() {
  int n, i;
  scanf("%d%d", &n, &m);
  waiting.setsize(m), leaving.setsize(m);
  for (i = 1; i <= n; i++) {
    scanf("%lld%d%d", &p[i].ti, &p[i].from, &p[i].to);
    p[i].id = i;
  }
  sort(p + 1, p + 1 + n);
  i = 1;
  while (cnt < n) {
    for (auto nv : out[level]) {
      cnt++;
      ans[nv.id] = T;
      ots.erase(level);
      leaving.update(level, -1);
    }
    while (i <= n && p[i].ti == T) {
      in[p[i].from].push_back(p[i]);
      ins.insert(p[i].from);
      waiting.update(p[i].from, 1);
      i++;
    }
    for (auto nv : in[level]) {
      ins.erase(level);
      waiting.update(level, -1);
      ots.insert(nv.to);
      leaving.update(nv.to, 1);
      out[nv.to].push_back(nv);
    }
    out[level].clear();
    in[level].clear();
    if (cnt >= n) break;
    if (stay()) {
      if (i <= n && T <= p[i].ti) {
        T = p[i].ti;
      }
    } else {
      set<int>::iterator iter;
      int ret = getdirection();
      long long delta = n + 1;
      if (i <= n) {
        delta = min(delta, p[i].ti - T);
      }
      if (ret == 1) {
        iter = ins.upper_bound(level);
        if (iter != ins.end()) {
          delta = min(delta, (long long)(*iter - level));
        }
        iter = ots.upper_bound(level);
        if (iter != ots.end()) {
          delta = min(delta, (long long)*iter - level);
        }
        level += delta;
        T += delta;
      } else {
        if (!ins.empty() && level > *ins.begin()) {
          iter = prev(ins.lower_bound(level));
          delta = min(delta, (long long)level - *iter);
        }
        if (!ots.empty() && level > *ots.begin()) {
          iter = prev(ots.lower_bound(level));
          delta = min(delta, (long long)level - *iter);
        }
        level -= delta;
        T += delta;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
