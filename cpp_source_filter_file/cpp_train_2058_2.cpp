#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int P = 1000000007;
int n, d;
vector<int> f[N];
int inv[N];
int val[N][N];
int poly[N], tmp[N], hp[N], g[N];
void dfs(int u);
int rev(int a);
void exGcd(int a, int b, int& x, int& y);
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    f[p].push_back(i);
  }
  dfs(1);
  tmp[0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = i + 1; j; --j)
      tmp[j] = (tmp[j - 1] + (long long)tmp[j] * (P - i)) % P;
    tmp[0] = tmp[0] * (long long)(P - i) % P;
  }
  for (int i = 0; i <= n; ++i) {
    memcpy(g, tmp, sizeof(g));
    for (int j = n; j >= 0; --j) {
      hp[j] = g[j + 1];
      g[j] = (g[j] + i * (long long)hp[j]) % P;
    }
    int r = 1;
    for (int j = 0; j < i; ++j) r = r * (long long)(i - j) % P;
    for (int j = n; j > i; --j) r = r * (long long)(P + i - j) % P;
    r = rev(r) * (long long)val[1][i] % P;
    for (int j = 0; j <= n; ++j) poly[j] = (poly[j] + hp[j] * (long long)r) % P;
  }
  int ans = 0, x = 1;
  for (int i = 0; i <= n; ++i) {
    ans = (ans + x * (long long)poly[i]) % P;
    x = x * (long long)d % P;
  }
  printf("%d\n", ans);
  return 0;
}
void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}
int rev(int a) {
  int x, y;
  exGcd(a, P, x, y);
  if (x < 0) x += P;
  return x;
}
void dfs(int u) {
  fill(val[u] + 1, val[u] + n + 1, 1);
  for (auto v : f[u]) {
    dfs(v);
    for (int i = 1; i <= n; ++i)
      val[u][i] = val[u][i] * (long long)val[v][i] % P;
  }
  for (int i = 2; i <= n; ++i) {
    val[u][i] += val[u][i - 1];
    if (val[u][i - 1] >= P) val[u][i - 1] -= P;
  }
}
