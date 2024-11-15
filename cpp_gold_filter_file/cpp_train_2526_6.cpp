#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long modInverse(long long n, long long M) { return powerM(n, M - 2, M); }
vector<long long> factu;
void factcalc(long long n, long long M) {
  factu.resize(n + 1);
  factu[0] = 1;
  for (long long i = 1; i <= n; i++) {
    factu[i] = mul(factu[i - 1], i, M);
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return mul(mul(factu[n], modInverse(factu[r], M), M),
             modInverse(factu[n - r], M), M);
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
vector<vector<long long> > adj;
vector<long long> depth, depth2;
void dfs(long long u, long long p, long long dis) {
  depth[u] = dis;
  for (auto& child : adj[u]) {
    if (child != p) {
      dfs(child, u, dis + 1);
    }
  }
}
void dfs2(long long u, long long p, long long dis) {
  depth2[u] = dis;
  for (auto& child : adj[u]) {
    if (child != p) {
      dfs2(child, u, dis + 1);
    }
  }
}
void solve() {
  long long n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  adj.resize(n);
  depth.resize(n);
  depth2.resize(n);
  a--;
  b--;
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(b, -1, 0);
  long long disa = depth[a];
  long long maxd = max_element(depth.begin(), depth.end()) - depth.begin();
  dfs2(maxd, -1, 0);
  if (disa <= da) {
    cout << "Alice\n";
  } else {
    if (db > 2 * da) {
      long long zz = *max_element(depth2.begin(), depth2.end());
      if (zz > 2 * da) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    } else {
      cout << "Alice\n";
    }
  }
  adj.clear();
  depth.clear();
  depth2.clear();
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
