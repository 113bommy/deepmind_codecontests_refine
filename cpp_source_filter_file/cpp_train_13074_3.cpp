#include <bits/stdc++.h>
const long long MOD = 1e9 + 7, INF = 1e18 + 1;
using namespace std;
long long n, m, banned[200000], p[200000], len[200000], p_m;
long long last[200000], u[200000], ph[200000];
vector<long long> fact[200010];
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long phi(long long n) {
  if (u[n]) return ph[n];
  u[n] = 1;
  long long d = n;
  long long result = n;
  for (long long i = 1; i < fact[d].size() && fact[d][i] * fact[d][i] <= n; i++)
    if (n % fact[d][i] == 0) {
      while (n % fact[d][i] == 0) n /= fact[d][i];
      result -= result / fact[d][i];
    }
  if (n > 1) result -= result / n;
  ph[d] = result;
  return result;
}
long long qpow(long long a, long long b, long long m) {
  long long s = 1;
  while (b) {
    if (b & 1) s = s * a % m;
    b /= 2;
    a = a * a % m;
  }
  return s;
}
long long solve(long long a, long long b) {
  int a_d = a, b_d = b, m_d = m;
  int d = gcd(a_d, m);
  a_d /= d;
  m_d /= d;
  b_d /= d;
  return b_d * qpow(a_d, phi(m_d) - 1, m_d) % m_d;
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    banned[x] = 1;
  }
  if (m == 1) {
    if (!banned[0])
      cout << "1\n0";
    else
      cout << 0;
    return 0;
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = i; j <= m; j += i) fact[j].push_back(i);
  }
  vector<pair<long long, long long> > v;
  for (long long i = 1; i < m; i++) v.emplace_back(make_pair(gcd(i, m), i));
  sort(v.begin(), v.end());
  for (long long i = 0; i < m; i++) {
    len[i] = 1;
    p[i] = 1;
    last[i] = -1;
  }
  last[1] = 0;
  long long mx_ind = -1;
  for (int i = 1; i < v.size(); i++) {
    if (banned[v[i].second]) continue;
    for (long long f : fact[v[i].second])
      if (last[f] != -1 && len[v[i].second] < len[v[last[f]].second] + 1) {
        len[v[i].second] = len[v[last[f]].second] + 1;
        p[v[i].second] = v[last[f]].second;
      }
    last[v[i].first] = i;
    if (mx_ind == -1 || len[mx_ind] < len[v[i].second]) mx_ind = v[i].second;
  }
  long long x = mx_ind;
  vector<long long> ans;
  if (mx_ind == -1) {
    if (!banned[0]) ans.push_back(0);
    cout << ans.size() << endl;
    for (long long a : ans) printf("%lld ", a);
    return 0;
  }
  while (x != 1) {
    long long a = p[x], b = x;
    ans.push_back(solve(a, b));
    if (a * solve(a, b) % m != b) cout << "NO!";
    x = p[x];
  }
  if (!banned[1]) ans.push_back(1);
  reverse(ans.begin(), ans.end());
  if (!banned[0]) ans.push_back(0);
  cout << ans.size() << endl;
  long long k = 1;
  for (long long a : ans) {
    printf("%lld ", a);
  }
}
