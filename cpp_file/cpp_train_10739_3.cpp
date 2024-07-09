#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const long long maxn = 1005;
const long long maxm = 1000005;
const long long dd = 998244353;
long long n, m;
long long a[maxm], sav[maxm], dp[maxn][maxn], col[maxn][maxn], L[maxn], R[maxn];
vector<long long> t[maxn];
struct nod {
  long long val, pos;
} uni[maxm];
inline bool cmp(nod x, nod y) { return x.val < y.val; }
inline long long read() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void scan() {
  m = read();
  n = read();
  for (long long k = 1; k <= n; k++) {
    uni[k].val = read();
    uni[k].pos = k;
  }
}
void prework() {
  long long lst = 0;
  sort(uni + 1, uni + n + 1, cmp);
  for (long long k = 1; k <= n; k++) {
    if (uni[k].val != uni[k - 1].val) lst++;
    sav[uni[k].pos] = lst;
  }
  m = lst;
  long long now = 0;
  for (long long k = 1; k <= n; k++)
    if (sav[k] != a[now]) a[++now] = sav[k];
  n = now;
  for (long long k = 1; k <= n; k++) t[a[k]].push_back(k);
  for (long long k = 1; k <= m; k++)
    L[k] = t[k][0], R[k] = t[k][t[k].size() - 1];
  for (long long k = 1; k <= m; k++)
    for (long long j = k + 1; j <= m; j++)
      if ((L[j] <= R[k] && R[k] < R[j]) || (R[j] >= L[k] && L[k] > L[j])) {
        puts("0");
        exit(0);
      }
  for (long long k = 1; k <= n; k++) {
    long long now = k;
    for (long long j = k; j <= n; j++)
      col[k][j] = a[j] > a[now] ? now : now = j;
  }
}
void solve() {
  for (long long k = 0; k <= n + 1; k++)
    for (long long j = 0; j <= k; j++) dp[k][j] = 1;
  dp[0][1] = dp[1][1];
  for (long long k = 2; k <= n; k++) {
    for (long long l = 1; l + k - 1 <= n; l++) {
      long long r = l + k - 1;
      long long x = col[l][r], siz = t[a[x]].size();
      long long ll = L[a[x]], rr = R[a[x]];
      long long ans1 = 0, ans2 = 0, ans3 = 1;
      for (long long k = l - 1; k < ll; k++)
        ans1 = (ans1 + dp[l][k] * dp[k + 1][ll - 1]) % dd;
      for (long long k = r + 1; k > rr; k--)
        ans2 = (ans2 + dp[k][r] * dp[rr + 1][k - 1]) % dd;
      dp[l][r] = ans1 * ans2 % dd;
      for (long long k = 0; k < siz - 1; k++)
        ans3 = ans3 * dp[t[a[x]][k] + 1][t[a[x]][k + 1] - 1] % dd;
      dp[l][r] = dp[l][r] * ans3 % dd;
    }
  }
  printf("%lld\n", dp[1][n]);
}
signed main() {
  scan();
  prework();
  solve();
  return 0;
}
