#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 20;
const long long mod = 1e9 + 7;
struct node {
  int lazy, t;
  long long sum;
  node() { lazy = t = sum = 0; }
};
node seg[maxn * 4];
int a[maxn];
long long fac[maxn];
node merge(node a, node b) {
  node c;
  c.sum = a.sum + b.sum;
  c.t = a.t + b.t;
  return c;
}
void build(int s, int e, int v) {
  if (e - s < 2) {
    seg[v].sum = s;
    return;
  }
  int m = (s + e) / 2;
  build(s, m, 2 * v);
  build(m, e, 2 * v + 1);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
void rem(int p, int s, int e, int v) {
  if (e - s < 2) {
    seg[v].sum = 0;
    seg[v].t = 1;
    return;
  }
  int m = (s + e) / 2;
  if (p < m)
    rem(p, s, m, 2 * v);
  else
    rem(p, m, e, 2 * v + 1);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
void ok(long long s, long long e, int v, long long val) {
  seg[v].sum += (e - s - seg[v].t) * val;
  seg[v].lazy += val;
}
void shift(int s, int e, int v) {
  if (e - s >= 2 && seg[v].lazy != 0) {
    int m = (s + e) / 2;
    ok(s, m, 2 * v, seg[v].lazy);
    ok(m, e, 2 * v + 1, seg[v].lazy);
  }
  seg[v].lazy = 0;
}
void add(int l, int r, int val, int s, int e, int v) {
  if (l <= s && e <= r) {
    ok(s, e, v, val);
    return;
  }
  if (r <= s || e <= l) return;
  shift(s, e, v);
  int m = (s + e) / 2;
  add(l, r, val, s, m, 2 * v);
  add(l, r, val, m, e, 2 * v + 1);
  seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
long long get(int l, int r, int s, int e, int v) {
  if (l <= s && e <= r) return seg[v].sum % mod;
  if (r <= s || e <= l) return 0;
  shift(s, e, v);
  int m = (s + e) / 2;
  return (get(l, r, s, m, 2 * v) + get(l, r, m, e, 2 * v + 1)) % mod;
}
int get_r(int l, int r, int s, int e, int v) {
  if (l <= s && e <= r) return seg[v].t;
  if (r <= s || e <= l) return 0;
  int m = (s + e) / 2;
  return get_r(l, r, s, m, 2 * v) + get_r(l, r, m, e, 2 * v + 1);
}
long long f(long long x) { return x * (x - 1) / 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac[2] = 1;
  for (long long i = 3; i < maxn; i++) fac[i] = (fac[i - 1] * i) % mod;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  build(0, n, 1);
  long long res = 0, tmp = 0;
  for (int i = 0; i < n; i++) {
    long long k = a[i] - get_r(0, a[i], 0, n, 1);
    long long w = ((n - i - 1 < 2) ? 1 : fac[n - i - 1] * 2) % mod;
    res += (((fac[n - i - 1] * f(n - i - 1)) % mod) * k) % mod;
    res += (w * get(0, a[i], 0, n, 1)) % mod;
    res += (((tmp * w) % mod) * k) % mod;
    res %= mod;
    tmp += get(a[i], a[i] + 1, 0, n, 1);
    rem(a[i], 0, n, 1);
    tmp %= mod;
    add(a[i], n, -1, 0, n, 1);
  }
  res += tmp;
  cout << res % mod << endl;
}
