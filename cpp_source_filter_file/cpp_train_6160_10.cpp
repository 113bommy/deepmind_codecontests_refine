#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
namespace PRT {
vector<int> dvs;
int fpow(int n, int k, int p) {
  int r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = (long long)r * n % p;
    n = (long long)n * n % p;
  }
  return r;
}
int query(int p) {
  dvs.clear();
  for (int i = 2; i * i < p; i++) {
    if ((p - 1) % i) continue;
    dvs.push_back(i);
    if (i * i != p - 1) dvs.push_back((p - 1) / i);
  }
  for (int i = 2; i < p; i++) {
    int flag = 1;
    for (int j = 0; j < dvs.size(); j++) {
      if (fpow(i, dvs[j], p) == 1) {
        flag = 0;
        break;
      }
    }
    if (flag) return i;
  }
  assert(0);
  return -1;
}
}  // namespace PRT
namespace FFT {
const int maxf = 1 << 20;
struct cp {
  long double x, y;
  cp(long double x = 0, long double y = 0) : x(x), y(y) {}
  cp operator+(const cp& rhs) const { return cp(x + rhs.x, y + rhs.y); }
  cp operator-(const cp& rhs) const { return cp(x - rhs.x, y - rhs.y); }
  cp operator*(const cp& rhs) const {
    return cp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
  }
  cp operator!() const { return cp(x, -y); }
} rts[maxf + 1];
cp fa[maxf], fb[maxf];
cp fc[maxf], fd[maxf];
int bitrev[maxf];
void fftinit() {
  int k = 0;
  while ((1 << k) < maxf) k++;
  bitrev[0] = 0;
  for (int i = 1; i < maxf; i++) {
    bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
  }
  long double PI = acos((long double)-1.0);
  rts[0] = rts[maxf] = cp(1, 0);
  for (int i = 1; i + i <= maxf; i++) {
    rts[i] = cp(cos(i * 2 * PI / maxf), sin(i * 2 * PI / maxf));
  }
  for (int i = maxf / 2 + 1; i < maxf; i++) {
    rts[i] = !rts[maxf - i];
  }
}
void dft(cp a[], int n, int sign) {
  static int isinit;
  if (!isinit) {
    isinit = 1;
    fftinit();
  }
  int d = 0;
  while ((1 << d) * n != maxf) d++;
  for (int i = 0; i < n; i++) {
    if (i < (bitrev[i] >> d)) {
      swap(a[i], a[bitrev[i] >> d]);
    }
  }
  for (int len = 2; len <= n; len <<= 1) {
    int delta = maxf / len * sign;
    for (int i = 0; i < n; i += len) {
      cp *x = a + i, *y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + maxf;
      for (int k = 0; k + k < len; k++) {
        cp z = *y * *w;
        *y = *x - z, *x = *x + z;
        x++, y++, w += delta;
      }
    }
  }
  if (sign < 0) {
    for (int i = 0; i < n; i++) {
      a[i].x /= n;
      a[i].y /= n;
    }
  }
}
void multiply(int a[], int b[], int na, int nb, long long c[], int dup = 0) {
  int n = na + nb - 1;
  while (n != (n & -n)) n += n & -n;
  for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
  for (int i = 0; i < na; i++) fa[i] = cp(a[i]);
  for (int i = 0; i < nb; i++) fb[i] = cp(b[i]);
  dft(fa, n, 1);
  if (dup) {
    for (int i = 0; i < n; i++) fb[i] = fa[i];
  } else {
    dft(fb, n, 1);
  }
  for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
  dft(fa, n, -1);
  for (int i = 0; i < n; i++) c[i] = (long long)floor(fa[i].x + 0.5);
}
void multiply(int a[], int b[], int na, int nb, int c[], int mod = (int)1e9 + 7,
              int dup = 0) {
  int n = na + nb - 1;
  while (n != (n & -n)) n += n & -n;
  for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
  static const int magic = 15;
  for (int i = 0; i < na; i++)
    fa[i] = cp(a[i] >> magic, a[i] & (1 << magic) - 1);
  for (int i = 0; i < nb; i++)
    fb[i] = cp(b[i] >> magic, b[i] & (1 << magic) - 1);
  dft(fa, n, 1);
  if (dup) {
    for (int i = 0; i < n; i++) fb[i] = fa[i];
  } else {
    dft(fb, n, 1);
  }
  for (int i = 0; i < n; i++) {
    int j = (n - i) % n;
    cp x = fa[i] + !fa[j];
    cp y = fb[i] + !fb[j];
    cp z = !fa[j] - fa[i];
    cp t = !fb[j] - fb[i];
    fc[i] = (x * t + y * z) * cp(0, 0.25);
    fd[i] = x * y * cp(0, 0.25) + z * t * cp(-0.25, 0);
  }
  dft(fc, n, -1), dft(fd, n, -1);
  for (int i = 0; i < n; i++) {
    long long u = ((long long)floor(fc[i].x + 0.5)) % mod;
    long long v = ((long long)floor(fd[i].x + 0.5)) % mod;
    long long w = ((long long)floor(fd[i].y + 0.5)) % mod;
    c[i] = ((u << 15) + v + (w << 30)) % mod;
  }
}
vector<int> multiply(vector<int> a, vector<int> b, int mod = (int)1e9 + 7) {
  static int fa[maxf], fb[maxf], fc[maxf];
  int na = a.size(), nb = b.size();
  for (int i = 0; i < na; i++) fa[i] = a[i];
  for (int i = 0; i < nb; i++) fb[i] = b[i];
  multiply(fa, fb, na, nb, fc, mod, a == b);
  int k = na + nb - 1;
  vector<int> res(k);
  for (int i = 0; i < k; i++) res[i] = fc[i];
  return res;
}
int fpow(int a, long long k, int p) {
  if (!k) return 1;
  int res = a, t = a;
  k--;
  while (k) {
    if (k & 1) res = (long long)res * t % p;
    t = (long long)t * t % p;
    k >>= 1;
  }
  return res;
}
vector<int> invert(vector<int> a, int n, int mod) {
  assert(a[0] != 0);
  vector<int> x(1, fpow(a[0], mod - 2, mod));
  while (x.size() < n) {
    vector<int> tmp(a.begin(), a.begin() + min(a.size(), 2 * x.size()));
    vector<int> nx = multiply(multiply(x, x, mod), tmp, mod);
    x.resize(2 * x.size());
    for (int i = 0; i < x.size(); i++) {
      x[i] += x[i];
      x[i] -= nx[i];
      if (x[i] < 0) x[i] += mod;
      if (x[i] >= mod) x[i] -= mod;
    }
  }
  x.resize(n);
  return x;
}
pair<vector<int>, vector<int> > divmod(vector<int> a, vector<int> b, int mod) {
  int n = a.size(), m = b.size();
  if (n < m) {
    return make_pair(vector<int>(), a);
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  vector<int> rb = invert(b, n - m + 1, mod);
  vector<int> d = multiply(a, rb, mod);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (d.size() > n - m + 1) d.pop_back();
  reverse(d.begin(), d.end());
  vector<int> r = multiply(d, b, mod);
  while (r.size() >= m) r.pop_back();
  for (int i = 0; i < m; i++) {
    r[i] = a[i] - r[i];
    if (r[i] < 0) r[i] += mod;
  }
  return make_pair(d, r);
}
vector<int> chirpz_transform(vector<int> a, int z, int k, int mod) {
  int n = a.size();
  vector<int> x;
  vector<int> y;
  int iz = fpow(z, mod - 2, mod);
  for (int i = 0; i < n; i++) {
    x.push_back((long long)a[i] * fpow(z, (long long)i * i, mod) % mod);
  }
  for (int i = 1 - n; i < k; i++) {
    y.push_back(fpow(iz, (long long)i * i, mod));
  }
  vector<int> r = FFT::multiply(x, y, mod);
  vector<int> res(k);
  for (int i = 0; i < k; i++) {
    res[i] = (long long)r[i + n - 1] * fpow(z, (long long)i * i, mod) % mod;
  }
  return res;
}
}  // namespace FFT
void chemthan() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> vals;
  for (int i = (0); i < (n); ++i) vals.push_back(s[i] - t[i]);
  auto ispr = [&](int k) {
    for (int i = 2; i * i <= k; i++) {
      if (k % i == 0) {
        return 0;
      }
    }
    return 1;
  };
  vector<int> pr;
  int st = 1e5;
  for (int it = (0); it < (100); ++it) {
    while (!ispr(st)) st++;
    pr.push_back(st++);
  }
  for (auto p : pr) {
    vector<int> a = vals;
    for (int& x : a) {
      x = (x % p + p) % p;
    }
    int z = PRT::query(p);
    vector<int> r = FFT::chirpz_transform(a, z, 1e5, p);
    for (int i = (1); i < (int((r).size())); ++i)
      if (!r[i]) {
        int x = fpow(z, i, p);
        if (1 < x && x < p - 2) {
          cout << p << " " << x << "\n";
          return;
        }
      }
  }
  assert(0);
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
