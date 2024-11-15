#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1, msiz = 2, mod = 1e9 + 7;
long long modplus(long long obj1, long long obj2) {
  long long res = obj1 + obj2;
  if (res >= mod) return res - mod;
  return res;
}
long long product(long long obj1, long long obj2) {
  return (obj1 * obj2) % mod;
}
long long modpow(long long x, long long h) {
  long long res = 1;
  for (; h; h >>= 1) {
    if (h & 1) res = product(res, x);
    x = product(x, x);
  }
  return res;
}
long long inverse(long long x) { return modpow(x, mod - 2); }
struct matrix {
  long long a[msiz][msiz];
  matrix() {
    for (int i = 0; i < msiz; i++)
      for (int j = 0; j < msiz; j++) a[i][j] = 0;
  }
  matrix operator*(matrix const &obj) {
    matrix res;
    for (int i = 0; i < msiz; i++)
      for (int j = 0; j < msiz; j++)
        for (int t = 0; t < msiz; t++)
          res.a[i][j] = modplus(res.a[i][j], product(a[i][t], obj.a[t][j]));
    return res;
  }
  matrix operator^(long long h) {
    matrix res, x;
    for (int i = 0; i < msiz; i++) res.a[i][i] = 1;
    for (int i = 0; i < msiz; i++)
      for (int j = 0; j < msiz; j++) x.a[i][j] = a[i][j];
    for (; h; h >>= 1) {
      if (h & 1) res = res * x;
      x = x * x;
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x;
  matrix st;
  st.a[0][0] = st.a[0][1] = 1;
  st.a[1][0] = 2;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    st = st ^ x;
  }
  cout << product(st.a[1][1], inverse(2)) << "/"
       << product(st.a[0][1] * 2 + st.a[1][1], inverse(2));
  return 0;
}
