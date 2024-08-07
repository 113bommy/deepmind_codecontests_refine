#include <bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 200200;
const int mod = 998244353;
inline long long pow(long long a, int b, int ans = 1) {
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
inline long long inverse(int x) { return pow(x, mod - 2); }
int n;
int head[maxn], next[maxn], w[maxn], p[maxn], maxp[maxn];
int fa[maxn], x[maxn];
inline void add(int fa, int x) { next[x] = head[fa], head[fa] = x; }
long long sum[maxn], ans;
inline void dfs0(int x) {
  for (int to = head[x]; to; to = next[to]) {
    dfs0(to);
    if (sum[to] > p[to]) {
      cout << -1 << '\n';
      exit(0);
    }
    const int d = std::min<int>(w[to] - 1, p[to] - sum[to]);
    w[to] -= d;
    p[to] -= d;
    sum[x] += sum[to] + w[to];
  }
}
inline long long dfs1(int x, long long max_add) {
  long long add = 0;
  for (int to = head[x]; to; to = next[to]) {
    int d = std::min<long long>(maxp[to] - p[to], max_add - add);
    add += d;
    p[to] += d;
    w[to] += d;
    ans += p[to];
    add += dfs1(to, std::min(max_add - add, p[to] - sum[to]));
  }
  return add;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = (2), iend = (n); i <= iend; ++i) {
    cin >> fa[i] >> x[i];
    cin >> w[x[i]] >> p[x[i]];
    maxp[x[i]] = p[x[i]];
    add(fa[i], x[i]);
  }
  dfs0(1);
  dfs1(1, 1e18);
  cout << n << '\n';
  for (int i = (2), iend = (n); i <= iend; ++i) {
    cout << fa[i] << ' ' << x[i] << ' ' << w[x[i]] << ' ' << p[x[i]] << '\n';
  }
}
