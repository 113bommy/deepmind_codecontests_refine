#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 1 << 30;
const int maxn = 1000000 + 5;
namespace pam {
int sz, tot, last;
int ch[maxn][26], len[maxn], fail[maxn];
int cnt[maxn], dep[maxn], dif[maxn], slink[maxn];
char s[maxn];
int node(int l) {
  sz++;
  memset(ch[sz], 0, sizeof(ch[sz]));
  len[sz] = l;
  fail[sz] = 0;
  cnt[sz] = 0;
  dep[sz] = 0;
  return sz;
}
void clear() {
  sz = -1;
  last = 0;
  s[tot = 0] = '$';
  node(0);
  node(-1);
  fail[0] = 1;
}
int getfail(int x) {
  while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
  return x;
}
void insert(char c) {
  s[++tot] = c;
  int now = getfail(last);
  if (!ch[now][c - 'a']) {
    int x = node(len[now] + 2);
    fail[x] = ch[getfail(fail[now])][c - 'a'];
    dep[x] = dep[fail[x]] + 1;
    ch[now][c - 'a'] = x;
    dif[x] = len[x] - len[fail[x]];
    if (dif[x] == dif[fail[x]])
      slink[x] = slink[fail[x]];
    else
      slink[x] = fail[x];
  }
  last = ch[now][c - 'a'];
  cnt[last]++;
}
}  // namespace pam
using pam::dif;
using pam::fail;
using pam::len;
using pam::slink;
int n, f[maxn], g[maxn], from[maxn];
char s[maxn], t[maxn];
int main() {
  pam::clear();
  scanf("%s", t + 1);
  n = strlen(t + 1);
  for (int i = 1; i <= n; i++) s[i * 2 - 1] = t[i];
  scanf("%s", t + 1);
  for (int i = 1; i <= n; i++) s[i * 2] = t[i];
  n *= 2;
  for (int i = 1; i <= n; i++) from[i] = f[i] = inf;
  for (int i = 1; i <= n; i++) {
    pam::insert(s[i]);
    if (i % 2 == 0 && s[i] == s[i - 1]) {
      f[i] = f[i - 2];
      from[i] = i - 2;
    }
    for (int x = pam::last; x > 1; x = pam::slink[x]) {
      g[x] = i - len[slink[x]] - dif[x];
      if (dif[x] == dif[fail[x]]) {
        if (f[g[x]] > f[g[fail[x]]]) {
          g[x] = g[fail[x]];
        }
      }
      if (i % 2 == 0) {
        if (f[g[x]] + 1 < f[i]) {
          f[i] = f[g[x]] + 1;
          from[i] = g[x];
        }
      }
    }
  }
  if (f[n] == inf) return puts("-1"), 0;
  printf("%d\n", f[n]);
  for (int i = n; i >= 2; i -= 2) {
    if (i - from[i] > 2) {
      printf("%d %d\n", from[i] / 2 + 1, i / 2);
    }
  }
  return 0;
}
