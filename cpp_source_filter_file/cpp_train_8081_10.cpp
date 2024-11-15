#include <bits/stdc++.h>
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")
using namespace std;
const int N = 1000005;
int S[N], n, fail[N], e[N][26], len[N], ec, last, anc[N], diff[N], m, dp[N],
    from[N], pre[N];
char s[N];
inline int newnode(int l) {
  pre[++ec] = -1;
  len[ec] = l;
  return ec;
}
inline void init() {
  last = 1;
  while (n) S[n--] = 0;
  S[0] = -1;
  while (~ec)
    len[ec] = fail[ec] = 0, memset(e[ec], 0, sizeof((e[ec])[0]) * (26)), ec--;
  newnode(0);
  newnode(-1);
  fail[0] = 1;
}
inline int match(int p) {
  while (S[n] != S[n - len[p] - 1]) p = fail[p];
  return p;
}
inline void extend(int c) {
  S[++n] = c;
  int cur = match(last);
  if (!e[cur][c]) {
    int p = newnode(len[cur] + 2);
    fail[p] = e[match(fail[cur])][c];
    e[cur][c] = p;
    diff[p] = len[p] - len[fail[p]];
    anc[p] = diff[p] == diff[fail[p]] ? anc[fail[p]] : fail[p];
  }
  last = e[cur][c];
}
int main() {
  scanf("%s", s + 1);
  for (register int i = 1, _lim_ = strlen(s + 1); i <= _lim_; i++)
    S[(i << 1) - 1] = s[i] - 'a';
  scanf("%s", s + 1);
  for (register int i = 1, _lim_ = strlen(s + 1); i <= _lim_; i++)
    S[i << 1] = s[i] - 'a';
  m = strlen(s + 1) << 1;
  init();
  for (register int i = 1, _lim_ = m; i <= _lim_; i++) {
    extend(S[i]);
    dp[i] = N;
    for (int x = last; x; x = anc[x]) {
      if (anc[x] != fail[x])
        pre[x] = pre[fail[x]];
      else
        pre[x] = -1;
      int p = i - len[anc[x]] - diff[x];
      if (pre[x] == -1 || pre[x] != -1 && dp[p] + 1 < dp[pre[x]]) pre[x] = p;
      if ((~i & 1) && ~pre[x] && dp[pre[x]] + 1 < dp[i])
        dp[i] = dp[pre[x]] + 1, from[i] = pre[x];
    }
    if ((~i & 1) && S[i] == S[i - 1] && dp[i - 2] < dp[i])
      dp[i] = dp[i - 2], from[i] = i - 2;
  }
  if (dp[m] == N) puts("-1"), exit(0);
  printf("%d\n", dp[m]);
  for (int i = m; i; i = from[i])
    if (from[i] + 2 != i) printf("%d %d\n", from[i] + 2 >> 1, i >> 1);
  return 0;
}
