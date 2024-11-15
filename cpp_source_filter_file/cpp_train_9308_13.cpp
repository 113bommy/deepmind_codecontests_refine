#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
const int inf = 0x7fffffff;
struct P {
  int x, y;
  int get(bool _x) {
    if (_x) return x;
    return y;
  }
  P() {}
  P(int _x, int _y) : x(_x), y(_y) {}
};
bool cmpX(const P &a, const P &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmpY(const P &a, const P &b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
struct L {
  int k, a, b;
  L() {}
  L(int _k, int _a, int _b) : k(_k), a(_a), b(_b) {}
};
vector<P> pr, pb;
vector<int> idr, idb;
bool ok[N][N];
void format(int n, vector<P> &p, bool _x, vector<int> &id) {
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p.push_back(P(x - y, x + y));
  }
  sort(p.begin(), p.end(), _x ? cmpX : cmpY);
  for (int i = 0, j; i < p.size(); i = j) {
    for (j = i + 1; j < p.size(); ++j) {
      if (p[j].get(_x) != p[i].get(_x)) break;
    }
    id.push_back(i);
    id.push_back(j - 1);
  }
}
void work(vector<P> &p, vector<int> &id, vector<L> &l, bool x, int t) {
  for (int i = 0; i < id.size(); i += 2) {
    int a = -inf, b;
    for (int j = id[i];;) {
      int z = p[j].get(!x), key = p[j].get(x);
      if (a == -inf)
        a = z - t, b = z + t;
      else if (a >= z - t)
        b = z + t;
      else {
        l.push_back(L(key, a, b));
        a = z - t, b = z + t;
      }
      ++j;
      if (j == id[i + 1] + 1) {
        l.push_back(L(key, a, b));
        break;
      }
    }
  }
}
bool check(int t) {
  vector<L> lr, lb;
  work(pr, idr, lr, 1, t);
  work(pb, idb, lb, 0, t);
  memset(ok, 0, sizeof(ok));
  for (int i = 0; i < lr.size(); ++i) {
    vector<int> c;
    L r = lr[i];
    for (int j = 0; j < lb.size(); ++j) {
      L b = lb[j];
      if (r.k >= b.a && r.k <= b.b && b.k >= r.a && b.k <= r.b) c.push_back(j);
    }
    for (int j = 0; j < c.size(); ++j) {
      for (int k = j + 1; k < c.size(); ++k) {
        if (!ok[c[j]][c[k]])
          ok[c[j]][c[k]] = 1;
        else
          return 1;
      }
    }
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  format(n, pb, 0, idb);
  format(m, pr, 1, idr);
  int _l = 1, _r = 1e8, ans = -1;
  while (_l <= _r) {
    int mid = (_l + _r) >> 1;
    if (check(mid * 2))
      _r = mid - 1, ans = mid;
    else
      _l = mid + 1;
  }
  if (ans == -1)
    puts("Poor Sereja!");
  else
    printf("%d\n", ans);
  return 0;
}
