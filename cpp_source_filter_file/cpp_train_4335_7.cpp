#include <bits/stdc++.h>
using namespace std;
int mod;
int a[100010];
vector<int> ps;
vector<pair<int, int> > f[100010];
const int N = 1 << 16;
int e[N];
long long b[N + N];
int pow(int p, int k) {
  if (k == 0) return 1;
  if (k == 1) return p;
  long long res = pow(p, k / 2);
  res = res * res % mod;
  if (k & 1) {
    res = res * p % mod;
  }
  return res;
}
void build() {
  for (int i = N - 1; i > 0; i--) {
    b[i] = b[i + i] * b[i + i + 1] % mod;
  }
}
void upd(int x, int v) {
  e[x] += v;
  b[x + N] = pow(ps[x], e[x]);
  x += N;
  while (x > 1) {
    x >>= 1;
    b[x] = b[x + x] * b[x + x + 1] % mod;
  }
}
void g(int p, int y) {
  if (p <= 1) return;
  for (int j = 0; j < f[p].size(); j++) {
    upd(f[p][j].first, y * f[p][j].second);
  }
}
int solve(int n, int l) {
  int res = 0;
  if (n < l) return 0;
  for (int i = 0; i < N; i++) {
    e[i] = 0;
    b[i + N] = 1;
  }
  for (int i = l + 1; i <= n; i++) {
    for (int j = 0; j < f[i].size(); j++) {
      e[f[i][j].first] += f[i][j].second;
    }
  }
  for (int i = 2; i <= n - l; i++) {
    for (int j = 0; j < f[i].size(); j++) {
      e[f[i][j].first] -= f[i][j].second;
    }
  }
  for (int i = 0; i < ps.size(); i++) {
    b[i + N] = pow(ps[i], e[i]);
  }
  build();
  for (int i = l; i <= n; i++) {
    int p = (i + l) / 2;
    res += b[1];
    if (res >= mod) res -= mod;
    if ((l - i) % 2 == 0) {
      g(p + 1, -1);
    } else {
      g((i - l) / 2 + 1, -1);
    }
    g(n - i, 1);
  }
  return res;
}
int main() {
  int n, l, r;
  ps.push_back(1);
  for (int i = 2; i < 100010; i++) {
    if (a[i]) {
      f[i] = f[i / ps[a[i]]];
      int fo = 0;
      for (int j = 0; j < f[i].size(); j++) {
        if (f[i][j].first == a[i]) {
          f[i][j].second++;
          fo = 1;
        }
      }
      if (!fo) {
        f[i].push_back(make_pair(a[i], 1));
      }
      continue;
    }
    a[i] = ps.size();
    for (int j = i + i; j < 100010; j += i) {
      a[j] = a[i];
    }
    f[i].push_back(make_pair(a[i], 1));
    ps.push_back(i);
  }
  scanf("%d%d%d%d", &n, &mod, &l, &r);
  int ans = solve(n, l);
  ans -= solve(n, r + 1);
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}
