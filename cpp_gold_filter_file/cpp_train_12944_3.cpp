#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[505];
int t[1000005][26] = {}, cnt[1000005] = {}, p[1000005], pind[1000005],
    dpos[1000005], mul[1000005];
bool used[1000005];
int sz = 1, dsz = 0;
int d[5005][2005];
int f[2005], g[2005];
int main() {
  scanf("%d%d", &n, &k);
  cnt[0] = n;
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%s", s);
    int len = strlen(s);
    int pos = 0;
    for (int i = 0; i < (int)(len); ++i) {
      int let = s[i] - 'a';
      if (!t[pos][let]) {
        t[pos][let] = sz;
        p[sz] = pos;
        pind[sz] = let;
        ++sz;
      }
      pos = t[pos][let];
      ++cnt[pos];
    }
  }
  for (int i = 0; i < (int)(sz); ++i) used[i] = true, mul[i] = 1;
  for (int i = sz - 1; i > 0; --i) {
    for (int j = 0; j < (int)(26); ++j)
      if (t[i][j] && cnt[t[i][j]] == cnt[i]) {
        t[p[i]][pind[i]] = t[i][j];
        ++mul[t[i][j]];
        used[i] = false;
        break;
      }
  }
  for (int i = sz - 1; i >= 0; --i)
    if (used[i]) {
      dpos[i] = dsz;
      int mx = min(k, cnt[i]), cur = 0;
      for (int j = 0; j < (int)(mx + 1); ++j) f[j] = 0;
      for (int j = 0; j < (int)(26); ++j)
        if (t[i][j]) {
          int pos = t[i][j];
          int mx2 = min(k, cnt[pos]);
          int *h = d[dpos[pos]];
          int newCur = min(mx, cur + mx2);
          for (int q = 0; q <= newCur; ++q) g[q] = 0;
          for (int q = 0; q <= cur; ++q) {
            int upTo = min(mx2, mx - q);
            for (int w = 0; w <= upTo; ++w) {
              g[q + w] = max(g[q + w], f[q] + h[w]);
            }
          }
          cur = newCur;
          for (int q = 0; q <= cur; ++q) f[q] = g[q];
        }
      d[dsz][0] = f[0];
      for (int j = 1; j <= mx; ++j) d[dsz][j] = max(d[dsz][j - 1], f[j]);
      if (i)
        for (int j = 0; j < (int)(mx + 1); ++j)
          d[dsz][j] += mul[i] * (j * (j - 1)) / 2;
      ++dsz;
    }
  cout << d[dpos[0]][k] << endl;
  return 0;
}
