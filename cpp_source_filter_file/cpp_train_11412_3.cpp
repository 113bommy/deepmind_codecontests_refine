#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1e9 + 7;
struct SegBeats {
  int n;
  struct node {
    ll sum, mx, smx, cnt;
  };
  node comb(const node &a, const node &b) {
    if (a.mx < b.mx) return comb(b, a);
    node ans;
    ans.sum = a.sum + b.sum;
    if (a.mx == b.mx) {
      ans.mx = a.mx;
      ans.cnt = a.cnt + b.cnt;
      ans.smx = max(a.smx, b.smx);
    } else {
      ans.mx = a.mx;
      ans.cnt = a.cnt;
      ans.smx = max(a.smx, b.mx);
    }
    return ans;
  }
  vector<node> st;
  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = {oo, oo, -oo, 1};
      return;
    }
    int mid = (L + R) / 2;
    build(2 * p, L, mid);
    build(2 * p + 1, mid + 1, R);
    st[p] = comb(st[2 * p], st[2 * p + 1]);
  }
  void propmx(int p, int L, int R) {
    if (L == R) return;
    if (st[p].mx < st[2 * p].mx) {
      st[2 * p].sum -= (st[2 * p].mx - st[p].mx) * st[2 * p].cnt;
      st[2 * p].mx = st[p].mx;
    }
    if (st[p].mx < st[2 * p + 1].mx) {
      st[2 * p + 1].sum -= (st[2 * p + 1].mx - st[p].mx) * st[2 * p].cnt;
      st[2 * p + 1].mx = st[p].mx;
    }
  }
  void updmin(int p, int L, int R, int i, int j, int x) {
    propmx(p, L, R);
    if (i > R or j < L) return;
    if (st[p].mx <= x) return;
    if (L >= i and R <= j and st[p].smx < x) {
      st[p].sum -= (st[p].mx - x) * st[p].cnt;
      st[p].mx = x;
      return;
    }
    int mid = (L + R) / 2;
    updmin(2 * p, L, mid, i, j, x);
    updmin(2 * p + 1, mid + 1, R, i, j, x);
    st[p] = comb(st[2 * p], st[2 * p + 1]);
  }
  ll querysum(int p, int L, int R, int i, int j) {
    propmx(p, L, R);
    if (i > R or j < L) return 0;
    if (L >= i and R <= j) return st[p].sum;
    int mid = (L + R) / 2;
    return querysum(2 * p, L, mid, i, j) +
           querysum(2 * p + 1, mid + 1, R, i, j);
  }
  void upd(int p, int L, int R, int i, int val) {
    propmx(p, L, R);
    if (i < L or i > R) return;
    if (L == R) {
      st[p].sum = val;
      st[p].cnt = 1;
      st[p].mx = val;
      return;
    }
    int mid = (L + R) / 2;
    upd(2 * p, L, mid, i, val);
    upd(2 * p + 1, mid + 1, R, i, val);
    st[p] = comb(st[2 * p], st[2 * p + 1]);
  }
  SegBeats(int sz) : n(sz), st(4 * sz) { build(1, 1, n); }
  void upd(int i, int val) { upd(1, 1, n, i, val); }
  void updmin(int i, int j, int x) { updmin(1, 1, n, i, j, x); }
  ll querysum(int i, int j) { return querysum(1, 1, n, i, j); }
};
const int N = 100005;
int n;
int m;
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  SegBeats stp(N), stneg(N);
  SegBeats tmpp(N), tmpneg(N);
  set<int> posp, posneg;
  for (int i = 0; i < N; i++) {
    posp.insert(i);
    posneg.insert(i);
    stp.upd(i, 0);
    stneg.upd(i, 0);
  }
  while (t--) {
    int type, x, y, val;
    scanf("%d %d %d", &type, &x, &y);
    y--;
    if (type == 1) {
      scanf("%d", &val);
      if (val > 0) {
        stp.updmin(x, y, val);
        tmpp.updmin(x, y, val);
        auto it = posp.lower_bound(x);
        while (it != posp.end() and *it <= y) {
          if (!posneg.count(*it)) {
            stp.upd(*it, (int)tmpp.querysum(*it, *it));
            stneg.upd(*it, (int)tmpneg.querysum(*it, *it));
          }
          it = posp.erase(it);
        }
      } else {
        stneg.updmin(x, y, -val);
        tmpneg.updmin(x, y, -val);
        auto it = posneg.lower_bound(x);
        while (it != posneg.end() and *it <= y) {
          if (!posp.count(*it)) {
            stp.upd(*it, (int)tmpp.querysum(*it, *it));
            stneg.upd(*it, (int)tmpneg.querysum(*it, *it));
          }
          it = posneg.erase(it);
        }
      }
    } else if (type == 2) {
      printf("%lld\n", stp.querysum(x, y) + stneg.querysum(x, y));
    } else
      assert(0);
  }
}
