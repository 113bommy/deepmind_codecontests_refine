#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int sz = 1 << 15;
char inbuf[sz], outbuf[sz];
char *pinbuf = inbuf + sz;
char *poutbuf = outbuf;
inline char _getchar() {
  if (pinbuf == inbuf + sz) fread(inbuf, 1, sz, stdin), pinbuf = inbuf;
  return *(pinbuf++);
}
inline void _putchar(char x) {
  if (poutbuf == outbuf + sz) fwrite(outbuf, 1, sz, stdout), poutbuf = outbuf;
  *(poutbuf++) = x;
}
inline void flush() {
  if (poutbuf != outbuf)
    fwrite(outbuf, 1, poutbuf - outbuf, stdout), poutbuf = outbuf;
}
}  // namespace IO
inline int read() {
  int x = 0, p = 1;
  char c = IO::_getchar();
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = IO::_getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = IO::_getchar();
  return x * p;
}
namespace Mymath {
long long qp(long long x, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans;
}
long long inv(long long x, long long mod) { return qp(x, mod - 2, mod); }
long long C(long long N, long long K, long long fact[], long long mod) {
  return fact[N] * inv(fact[K], mod) % mod * inv(fact[N - K], mod) % mod;
}
template <typename Tp>
Tp gcd(Tp A, Tp B) {
  if (B == 0) return A;
  return gcd(B, A % B);
}
template <typename Tp>
Tp lcm(Tp A, Tp B) {
  return A * B / gcd(A, B);
}
};  // namespace Mymath
namespace fwt {
using namespace Mymath;
void FWT(int a[], int n, long long mod) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) % mod, a[i + j + d] = (x - y + mod) % mod;
      }
}
void UFWT(int a[], int n, long long mod) {
  long long rev = inv(2, mod);
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = 1LL * (x + y) * rev % mod,
              a[i + j + d] = (1LL * (x - y) * rev % mod + mod) % mod;
      }
}
void solve(int a[], int b[], int n, long long mod) {
  FWT(a, n, mod);
  FWT(b, n, mod);
  for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % mod;
  UFWT(a, n, mod);
}
};  // namespace fwt
namespace Maxflow {
const int Maxn = 1005;
struct edge {
  int to, rev, cap;
  edge(int _to, int _rev, int _cap) { to = _to, rev = _rev, cap = _cap; }
};
int src = 1002, snk = 1003;
vector<edge> G[Maxn];
int dist[Maxn], seen[Maxn];
int n;
void Clear() {
  for (int i = 0; i < Maxn; i++) G[i].clear();
}
void bfs(int s) {
  for (int i = 0; i < Maxn; i++) dist[i] = -1;
  dist[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = 0; i < G[x].size(); i++) {
      edge &e = G[x][i];
      if (e.cap && dist[e.to] == -1) {
        dist[e.to] = dist[x] + 1;
        Q.push(e.to);
      }
    }
  }
}
int dfs(int now, int dest, int fl) {
  if (now == dest) return fl;
  for (int &i = seen[now]; i < G[now].size(); i++) {
    edge &ed = G[now][i];
    if (ed.cap && dist[ed.to] == dist[now] + 1) {
      int f = dfs(ed.to, dest, min(fl, ed.cap));
      if (f) {
        ed.cap -= f;
        G[ed.to][ed.rev].cap += f;
        return f;
      }
    }
  }
  return 0;
}
int dinic(int s = src, int t = snk) {
  int ret = 0;
  while (1) {
    memset(seen, 0, sizeof(seen));
    bfs(s);
    if (dist[t] == -1) return ret;
    int f = dfs(s, t, 2147483647);
    while (f) {
      ret += f;
      f = dfs(s, t, 2147483647);
    }
  }
}
};  // namespace Maxflow
namespace Geometry {
struct iP {
  long long x, y;
  iP(long long _x, long long _y) { x = _x, y = _y; }
  iP() { x = y = 0; }
  iP operator+(iP p) { return iP(x + p.x, y + p.y); }
  iP operator-(iP p) { return iP(x - p.x, y - p.y); }
  iP operator*(long long k) { return iP(x * k, y * k); }
  long long det(iP p) { return x * p.y - y * p.x; }
  long long dot(iP p) { return x * p.x + y * p.y; }
  long long dist() { return x * x + y * y; }
  bool operator<(const iP &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
};
struct dP {
  double x, y;
  dP(double _x, double _y) { x = _x, y = _y; }
  dP() { x = y = 0.0; }
  dP operator+(dP p) { return dP(x + p.x, y + p.y); }
  dP operator-(dP p) { return dP(x - p.x, y - p.y); }
  dP operator*(double k) { return dP(x * k, y * k); }
  double det(dP p) { return x * p.y - y * p.x; }
  double dot(dP p) { return x * p.x + y * p.y; }
  double dist() { return x * x + y * y; }
  bool operator<(const dP &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
};
vector<iP> convex_hull(iP X[], int l) {
  vector<iP> ret;
  sort(X + 1, X + 1 + l);
  ret.push_back(X[1]);
  for (int i = 2; i <= l; i++) {
    while (ret.size() >= 2 &&
           (ret[ret.size() - 2] - X[i]).det(ret[ret.size() - 1] - X[i]) >= 0) {
      ret.pop_back();
    }
    ret.push_back(X[i]);
  }
  int rs = ret.size() + 1;
  for (int i = l - 1; i >= 1; i--) {
    while (ret.size() >= rs &&
           (ret[ret.size() - 2] - X[i]).det(ret[ret.size() - 1] - X[i]) >= 0) {
      ret.pop_back();
    }
    ret.push_back(X[i]);
  }
  return ret;
}
};  // namespace Geometry
const int Maxn = 1005;
const int mod = 1e9 + 7;
int n, k;
int dp[Maxn][Maxn][2][2];
int add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
long long fact[Maxn];
long long ans[Maxn];
using namespace Mymath;
int main() {
  scanf("%d %d", &n, &k);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  dp[0][0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int fi = 0; fi < 2; fi++) {
        for (int fi1 = 0; fi1 < 2; fi1++) {
          if (dp[i][j][fi][fi1]) {
            add(dp[i + 1][j][fi1][1], dp[i][j][fi][fi1]);
            if (i != n - 1) add(dp[i + 1][j + 1][fi1][0], dp[i][j][fi][fi1]);
            if (fi) {
              add(dp[i + 1][j + 1][fi1][1], dp[i][j][fi][fi1]);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ans[i] += dp[n][i][j][k];
      }
    }
    ans[i] %= mod;
    ans[i] = ans[i] * fact[n - i] % mod;
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      ans[i] -= C(j, i, fact, mod) * ans[j];
      ans[i] = (ans[i] % mod + mod) % mod;
    }
  }
  printf("%lld\n", ans[k]);
  return ~~(0 ^ 0 ^ 0);
}
