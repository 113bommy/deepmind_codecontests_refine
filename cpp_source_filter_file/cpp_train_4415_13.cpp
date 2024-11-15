#include <bits/stdc++.h>
using namespace std;
const long long B = 314000000, A = (long long)1e10, N = 228228;
pair<long long, long long> xy;
priority_queue<pair<long long, long long> > g;
vector<long long> w[N], b[N], c[N];
long long f[N], q[N], x, y, i, j, n, m, a[N], e, t, k[N], s[N], o[2][N];
long long rec(long long v) {
  if (f[v]) return o[1][v];
  f[v] = 1;
  long long t, i, j, y, k, ok;
  for (i = 0; i < w[v].size(); i++) {
    j = w[v][i], ok = 0;
    for (k = 0; k < c[j].size(); k++)
      if (o[0][c[j][k]] == A) ok = 1;
    if (ok) continue;
    t = 0;
    for (k = 0; k < c[j].size(); k++) {
      y = c[j][k];
      if (y == -2)
        t++;
      else if (f[y] == 1)
        ok = 1;
      else {
        t = min(t + rec(y), B);
        if (q[y]) ok = 1;
      }
    }
    o[1][v] = max(o[1][v], min(t, B));
    if (ok) q[v] = 1;
  }
  f[v] = 2;
  return o[1][v];
}
int main() {
  cin >> m >> n;
  for (i = 0; i < m; i++) {
    e = 0;
    scanf("%d%d", &a[i], &e);
    a[i]--, w[a[i]].push_back(i);
    while (e--) {
      t = 0;
      scanf("%lld", &t);
      t--;
      c[i].push_back(t);
      if (t == -2)
        k[i]++;
      else
        b[t].push_back(i), s[i]++;
    }
    if (!s[i]) g.push(make_pair(-k[i], a[i]));
  }
  for (i = 0; i < n; i++) o[0][i] = A;
  while (g.size()) {
    xy = g.top(), g.pop();
    x = -xy.first, y = xy.second;
    if (f[y]) continue;
    f[y] = 1;
    o[0][y] = x;
    for (i = 0; i < b[y].size(); i++) {
      t = b[y][i], k[t] = min(k[t] + x, B), s[t]--;
      if (!s[t]) g.push(make_pair(-k[t], a[t]));
    }
  }
  for (i = 0; i < n; i++) f[i] = 0;
  for (i = 0; i < n; i++)
    if (o[0][i] != A) rec(i);
  for (i = 0; i < n; i++)
    if (o[0][i] == A)
      puts("-1 -1");
    else
      printf("%d %d\n", o[0][i], (q[i] ? -2 : o[1][i]));
}
