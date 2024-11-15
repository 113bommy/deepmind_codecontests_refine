#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct mat {
  long long a[109][109];
  int n;
  mat(int _n, long long v = 0) {
    n = _n;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) a[i][i] = v;
  }
};
mat operator*(mat a, mat b) {
  int n = a.n;
  mat ret(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
  return ret;
}
mat operator^(mat a, int n) {
  mat ret(a.n, 1);
  if (!n) return ret;
  ret = a ^ (n >> 1);
  if (n & 1) return ret * ret * a;
  return ret * ret;
}
long long aa[109], res, bb[109];
int n, b, k, x;
int main() {
  cin >> n >> b >> k >> x;
  mat ans(x, 0);
  for (int i = 0, v; i < n; i++) {
    cin >> v, v %= x, aa[v]++;
    for (int j = 0; j < x; j++) {
      long long r = (10 * j + v) % x;
      ans.a[r][j]++;
    }
  }
  ans = ans ^ (b - 1);
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++) bb[j] = (bb[j] + aa[i] * ans.a[j][i]) % MOD;
  cout << bb[k];
}
