#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long inf = 1000000000000000000;
const long long KOK = 100000;
const long long LOG = 30;
const long long li = 500005;
const long long mod = 1000000007;
long long n, m, b[li], a[li], k, flag, t, l, r, at;
long long cev;
string s;
char c;
vector<long long> v;
map<long long, long long> vis;
int32_t main(void) {
  scanf("%lld %lld %lld %lld", &n, &m, &l, &r);
  l--;
  r--;
  long long ll = l;
  l = l % (n + m);
  c = '.';
  r = l + min(r - ll, 50ll);
  for (long long i = 1; i <= n; i++) s += (i - 1) + 'a';
  c = s[(long long)s.size() - 1];
  for (long long i = 1; i <= m; i++) {
    s += c;
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  at = 0;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    at++;
    vis[s[i] - 'a'] = 1;
    if (at == n) break;
  }
  at = 0;
  for (long long i = 0; i <= 25; i++) {
    at++;
    if (at > n) break;
    if (vis[i]) {
      at--;
      continue;
    }
    s += (i + 'a');
  }
  c = s[(long long)s.size() - 1];
  for (long long i = 1; i <= m; i++) {
    s += c;
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  at = 0;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    at++;
    vis[s[i] - 'a'] = 1;
    if (at == n) break;
  }
  at = 0;
  for (long long i = 0; i <= 25; i++) {
    at++;
    if (at > n) break;
    if (vis[i]) {
      at--;
      continue;
    }
    s += (i + 'a');
  }
  c = s[(long long)s.size() - 1];
  for (long long i = 1; i <= m; i++) {
    s += c;
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  at = 0;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    at++;
    vis[s[i] - 'a'] = 1;
    if (at == n) break;
  }
  at = 0;
  for (long long i = 0; i <= 25; i++) {
    at++;
    if (at > n) break;
    if (vis[i]) {
      at--;
      continue;
    }
    s += (i + 'a');
  }
  c = s[(long long)s.size() - 1];
  for (long long i = 1; i <= m; i++) {
    s += c;
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  at = 0;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    at++;
    vis[s[i] - 'a'] = 1;
    if (at == n) break;
  }
  at = 0;
  for (long long i = 0; i <= 25; i++) {
    at++;
    if (at > n) break;
    if (vis[i]) {
      at--;
      continue;
    }
    s += (i + 'a');
  }
  c = s[(long long)s.size() - 1];
  for (long long i = 1; i <= m; i++) {
    s += c;
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  at = 0;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    at++;
    vis[s[i] - 'a'] = 1;
    if (at == n) break;
  }
  at = 0;
  for (long long i = 0; i <= 25; i++) {
    at++;
    if (at > n) break;
    if (vis[i]) {
      at--;
      continue;
    }
    s += ((i + 'a'));
  }
  for (long long j = 0; j <= 25; j++) vis[j] = 0;
  for (long long i = l; i <= r; i++) {
    vis[s[i] - 'a'] = 1;
  }
  cev = 0;
  for (long long i = 0; i <= 25; i++) {
    if (vis[i]) cev++;
  }
  long long cev1 = cev;
  if (n > 1) {
    cev = 0;
    s.clear();
    c = '.';
    for (long long i = 1; i <= n; i++) s += (i - 1) + 'a';
    c = s[(long long)s.size() - 2];
    for (long long i = 1; i <= m; i++) {
      s += c;
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    at = 0;
    for (long long i = (long long)s.size() - 1; i >= 0; i--) {
      at++;
      vis[s[i] - 'a'] = 1;
      if (at == n) break;
    }
    at = 0;
    for (long long i = 0; i <= 25; i++) {
      at++;
      if (at > n) break;
      if (vis[i]) {
        at--;
        continue;
      }
      s += (i + 'a');
    }
    c = s[(long long)s.size() - 2];
    for (long long i = 1; i <= m; i++) {
      s += c;
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    at = 0;
    for (long long i = (long long)s.size() - 1; i >= 0; i--) {
      at++;
      vis[s[i] - 'a'] = 1;
      if (at == n) break;
    }
    at = 0;
    for (long long i = 0; i <= 25; i++) {
      at++;
      if (at > n) break;
      if (vis[i]) {
        at--;
        continue;
      }
      s += (i + 'a');
    }
    c = s[(long long)s.size() - 2];
    for (long long i = 1; i <= m; i++) {
      s += c;
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    at = 0;
    for (long long i = (long long)s.size() - 1; i >= 0; i--) {
      at++;
      vis[s[i] - 'a'] = 1;
      if (at == n) break;
    }
    at = 0;
    for (long long i = 0; i <= 25; i++) {
      at++;
      if (at > n) break;
      if (vis[i]) {
        at--;
        continue;
      }
      s += (i + 'a');
    }
    c = s[(long long)s.size() - 2];
    for (long long i = 1; i <= m; i++) {
      s += c;
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    at = 0;
    for (long long i = (long long)s.size() - 1; i >= 0; i--) {
      at++;
      vis[s[i] - 'a'] = 1;
      if (at == n) break;
    }
    at = 0;
    for (long long i = 0; i <= 25; i++) {
      at++;
      if (at > n) break;
      if (vis[i]) {
        at--;
        continue;
      }
      s += (i + 'a');
    }
    c = s[(long long)s.size() - 2];
    for (long long i = 1; i <= m; i++) {
      s += c;
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    at = 0;
    for (long long i = (long long)s.size() - 1; i >= 0; i--) {
      at++;
      vis[s[i] - 'a'] = 1;
      if (at == n) break;
    }
    at = 0;
    for (long long i = 0; i <= 25; i++) {
      at++;
      if (at > n) break;
      if (vis[i]) {
        at--;
        continue;
      }
      s += ((i + 'a'));
    }
    for (long long j = 0; j <= 25; j++) vis[j] = 0;
    for (long long i = l; i <= r; i++) {
      vis[s[i] - 'a'] = 1;
    }
    cev = 0;
    for (long long i = 0; i <= 25; i++) {
      if (vis[i]) cev++;
    }
  } else
    cev = inf;
  cev = min(cev, cev1);
  printf("%lld\n", cev);
  return 0;
}
