#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5L + 11;
int a[N], b[N];
struct SegTree {
  bool f[N * 8];
  int v[N * 4][2];
  void build(int l, int r, int x = 1) {
    f[x] = v[x][1] = 0;
    v[x][0] = r - l;
    if (l + 1 != r) {
      build(l, (l + r) / 2, 2 * x);
      build((l + r) / 2, r, 2 * x + 1);
    }
  }
  void push(int x) {
    if (f[x]) swap(v[x][0], v[x][1]);
    f[2 * x] ^= f[x];
    f[2 * x + 1] ^= f[x];
    f[x] = 0;
  }
  void change(int l, int r, int ql, int qr, int x = 1) {
    push(x);
    if (ql == l && qr == r)
      f[x] = 1;
    else {
      if (qr <= (l + r) / 2)
        change(l, (l + r) / 2, ql, qr, 2 * x);
      else if (ql >= (l + r) / 2)
        change((l + r) / 2, r, ql, qr, 2 * x + 1);
      else {
        change(l, (l + r) / 2, ql, (l + r) / 2, 2 * x);
        change((l + r) / 2, r, (l + r) / 2, qr, 2 * x + 1);
      }
      push(2 * x);
      push(2 * x + 1);
      v[x][0] = v[2 * x][0] + v[2 * x + 1][0];
      v[x][1] = v[2 * x][1] + v[2 * x + 1][1];
    }
  }
  int query(int l, int r, int ql, int qr, int x = 1) {
    push(x);
    if (ql == l && qr == r) return v[x][0];
    if (qr <= (l + r) / 2) return query(l, (l + r) / 2, ql, qr, 2 * x);
    if (ql >= (l + r) / 2) return query((l + r) / 2, r, ql, qr, 2 * x + 1);
    return query(l, (l + r) / 2, ql, (l + r) / 2, 2 * x) +
           query((l + r) / 2, r, (l + r) / 2, qr, 2 * x + 1);
  }
} st;
vector<int> eves[N];
int c[2][N];
int main() {
  ios ::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  mp[0] = mp[(int)2e9L] = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[x] = 0;
  }
  {
    int c = 0;
    for (auto &i : mp) i.second = c++;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    a[i] = mp.lower_bound(a[i])->second;
    b[i] = (--mp.upper_bound(b[i]))->second;
    if (a[i] > b[i]) {
      i--;
      m--;
    }
  }
  for (int t : {0, 1}) {
    st.build(1, n + 1, 1);
    for (int i = 1; i <= n + 1; i++) eves[i].clear();
    for (int i = 1; i <= m; i++) {
      eves[a[i]].push_back(i);
      eves[b[i] + 1].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      for (int e : eves[i]) st.change(1, n + 1, a[e], n + 1, 1);
      if (i > 1) c[t][i] = st.query(1, n + 1, 1, i, 1);
    }
    for (int i = 1; i <= m; i++) {
      a[i] = n - a[i] + 1;
      b[i] = n - b[i] + 1;
      swap(a[i], b[i]);
    }
  }
  ll ans = n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) {
    int j = n - i + 1;
    ll t = c[0][i] + (j - 1 - c[1][j]);
    ans -= t * (t - 1) / 2;
  }
  cout << ans << '\n';
}
