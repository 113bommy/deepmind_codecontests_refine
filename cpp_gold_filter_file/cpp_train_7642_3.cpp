#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w, e, r, t = 0, c, v, *s[2000], *d = new int[4000000],
                  *f = new int[4000000], *g[2000], *h[2000];
  char *a[2000];
  cin >> q >> w;
  for (e = 0; e < q; e++) {
    s[e] = new int[w];
    g[e] = new int[w];
    h[e] = new int[w];
    for (r = 0; r < w; r++) {
      s[e][r] = g[e][r] = 0;
      h[e][r] = 1;
    }
    a[e] = new char[w + 1];
    scanf("%s", a[e]);
  }
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++) {
      if (a[e][r] == '<') g[e][r - 1]++;
      if (a[e][r] == '>') g[e][r + 1]++;
      if (a[e][r] == '^') g[e - 1][r]++;
      if (a[e][r] == 'v') g[e + 1][r]++;
    }
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++)
      if (g[e][r] == 0) {
        d[t] = e;
        f[t] = r;
        t++;
      }
  for (e = 0; e < t; e++) {
    c = d[e];
    v = f[e];
    if (a[d[e]][f[e]] == '#') continue;
    if (a[d[e]][f[e]] == '<') v--;
    if (a[d[e]][f[e]] == '>') v++;
    if (a[d[e]][f[e]] == '^') c--;
    if (a[d[e]][f[e]] == 'v') c++;
    if (s[c][v] == s[d[e]][f[e]] + 1)
      h[c][v]++;
    else if (s[c][v] < s[d[e]][f[e]] + 1) {
      s[c][v] = s[d[e]][f[e]] + 1;
      h[c][v] = 1;
    }
    g[c][v]--;
    if (g[c][v] == 0) {
      d[t] = c;
      f[t] = v;
      t++;
    }
  }
  if (t < q * w) {
    cout << -1;
    return 0;
  }
  t = 0;
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++)
      if (s[e][r] == t)
        c += h[e][r];
      else if (s[e][r] > t) {
        t = s[e][r];
        c = h[e][r];
      }
  if (t == 0)
    cout << 0;
  else if (c == 1)
    cout << t + t - 1;
  else
    cout << t + t;
  return 0;
}
