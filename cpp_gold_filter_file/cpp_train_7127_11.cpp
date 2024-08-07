#include <bits/stdc++.h>
using namespace std;
const int N = 2000100;
char s[N], t[N];
int a[55][55], k;
int F(char c) {
  if ('a' <= c && c <= 'z') return c - 'a';
  return c - 'A' + 26;
}
void work() {
  int n = k, m = k, INF = 1e9;
  vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    vector<int> minv(m + 1, INF);
    vector<char> used(m + 1, false);
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          int cur = a[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) minv[j] = cur, way[j] = j0;
          if (minv[j] < delta) delta = minv[j], j1 = j;
        }
      for (int j = 0; j <= m; ++j)
        if (used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  vector<int> ans(n + 1);
  for (int j = 1; j <= m; ++j) ans[p[j]] = j;
  cout << v[0] << endl;
  for (int j = 1; j <= m; j++) {
    ans[j]--;
    if (ans[j] < 26) {
      cout << (char)('a' + ans[j]);
    } else {
      cout << (char)('A' + ans[j] - 26);
    }
  }
}
int main() {
  int n;
  scanf("%d%d\n", &n, &k);
  gets(s);
  gets(t);
  for (int(i) = 0; (i) < (n); (i)++) a[F(s[i]) + 1][F(t[i]) + 1]--;
  work();
  return 0;
}
