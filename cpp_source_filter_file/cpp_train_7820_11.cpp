#include <bits/stdc++.h>
using namespace std;
int n;
long long mod, phm;
vector<int> pr;
array<vector<long long>, 9> pre;
const int MPRE = 2e6;
long long minv(long long x) {
  long long e = phm, res = 1;
  for (long long k = 1; k <= e; k *= 2) {
    if (k & e) res = (res * x) % mod;
    x = (x * x) % mod;
  }
  return res;
}
struct node {
  int l, r;
  long long sum, lz;
  array<int, 9> vp;
  node *left, *right;
  long long get() {
    long long res = sum;
    res = (res * lz) % mod;
    for (int i = 0; i < pr.size(); i++) {
      res = (res * pre[i][vp[i]]) % mod;
    }
    return res;
  }
  void merge() { sum = (left->get() + right->get()) % mod; }
  void push() {
    left->lz = (left->lz * lz) % mod;
    right->lz = (right->lz * lz) % mod;
    lz = 1;
    for (int i = 0; i < pr.size(); i++) {
      left->vp[i] += vp[i];
      right->vp[i] += vp[i];
      vp[i] = 0;
    }
  }
  node(int l, int r, vector<int> &a) : l(l), r(r) {
    lz = 1;
    for (int i = 0; i < pr.size(); i++) vp[i] = 0;
    if (l == r) {
      for (int i = 0; i < pr.size(); i++) {
        int p = pr[i];
        while (a[l] % p == 0) {
          a[l] /= p;
          vp[i]++;
        }
      }
      sum = a[l];
    } else {
      int m = (l + r) / 2;
      left = new node(l, m, a);
      right = new node(m + 1, r, a);
      merge();
    }
  }
  void upd(int x, int rl, int rr) {
    if (r < rl || rr < l) return;
    if (rl <= l && r <= rr) {
      for (int i = 0; i < pr.size(); i++) {
        int p = pr[i];
        while (x % p == 0) {
          x /= p;
          vp[i]++;
        }
      }
      lz = (lz * x) % mod;
      return;
    }
    push();
    left->upd(x, rl, rr);
    right->upd(x, rl, rr);
    merge();
  }
  void div(int x, int ps) {
    if (r < ps || ps < l) return;
    if (l == r) {
      for (int i = 0; i < pr.size(); i++) {
        int p = pr[i];
        while (x % p == 0) {
          x /= p;
          vp[i]--;
        }
      }
      lz = (lz * minv(x)) % mod;
      return;
    }
    push();
    left->div(x, ps);
    right->div(x, ps);
    merge();
  }
  long long qry(int rl, int rr) {
    if (r < rl || rr < l) return 0;
    if (rl <= l && r <= rr) {
      return get();
    }
    push();
    merge();
    return (left->qry(rl, rr) + right->qry(rl, rr)) % mod;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> mod;
  int tm = mod;
  phm = mod;
  for (int d = 2; d * d <= tm; d++) {
    if (tm % d) continue;
    pr.push_back(d);
    phm /= d;
    phm *= d - 1;
    while (tm % d == 0) tm /= d;
  }
  if (tm > 1) {
    pr.push_back(tm);
    phm /= tm;
    phm *= tm - 1;
  }
  for (int i = 0; i < pr.size(); i++) {
    long long p = pr[i];
    pre[i].push_back(1);
    for (int j = 0; j < MPRE; j++) pre[i].push_back((p * pre[i].back()) % mod);
  }
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  node tree(1, n, a);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      tree.upd(x, l, r);
    }
    if (t == 2) {
      int p, x;
      cin >> p >> x;
      tree.div(x, p);
    }
    if (t == 3) {
      int l, r;
      cin >> l >> r;
      cout << tree.qry(l, r) << endl;
    }
  }
}
