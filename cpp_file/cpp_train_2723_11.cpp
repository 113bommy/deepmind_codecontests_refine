#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a < 0 ? a + P : a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 4000;
int n, m, a[N], f[N][N], s1, s2, s, w[N], tmp[N], ans[N];
unordered_map<int, int> M;
int inv(int x) {
  if (!M.count(x)) return M[x] = kpow(x, P - 2);
  return M[x];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i < (n + 1); i++) cin >> a[i];
  for (int i = (1); i < (n + 1); i++) {
    cin >> w[i], s += w[i];
    if (a[i])
      s2 += w[i];
    else
      s1 += w[i];
  }
  f[0][0] = 1;
  for (int i = (1); i < (m + 1); i++) {
    for (int j = (0); j < (m + 1); j++) {
      int &t = f[i][j + 1], sum = s + j - (i - 1 - j);
      if (i - 1 - j > s1) continue;
      t = add(t, mul(f[i - 1][j], mul(j + s2, inv(sum))));
      int &t2 = f[i][j];
      t2 = add(t2, mul(f[i - 1][j], mul(sum - j - s2, inv(sum))));
    }
  }
  for (int i = (0); i < (m + 1); i++) {
    for (int j = (1); j < (n + 1); j++)
      if (a[j])
        ans[j] = add(ans[j], mul(mul(f[m][i], w[j]), mul(s2 + i, inv(s2))));
      else if (i <= s1)
        ans[j] = add(ans[j], mul(mul(f[m][m - i], w[j]), mul(s1 - i, inv(s1))));
  }
  for (int i = (1); i < (n + 1); i++) cout << ans[i] << "\n";
  return 0;
}
