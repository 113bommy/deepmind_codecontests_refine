#include <bits/stdc++.h>
char ch;
void re(int& x) {
  while (ch = getchar(), ch < 33)
    ;
  x = ch - 48;
  while (ch = getchar(), ch > 33) x = x * 10 + ch - 48;
}
using namespace std;
int n, k, q, c, a[13][100015];
bitset<1 << 12> f[100015];
int main() {
  re(n), re(k), re(q);
  c = k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) re(a[i][j]);
    for (int j = 0; j < (1 << 12); ++j) f[i][j] = (j >> (i - 1)) & 1;
  }
  for (int opt, a, b; q--;) {
    re(opt), re(a), re(b);
    if (opt == 1) f[++c] = f[a] | f[b];
    if (opt == 2) f[++c] = f[a] & f[b];
    if (opt == 3) {
      vector<pair<int, int> > x;
      x.clear();
      for (int i = 1; i <= k; ++i) x.push_back(make_pair(::a[i][b], i - 1));
      sort(x.begin(), x.end());
      for (int i = k - 1, now = 0; i >= 0; --i) {
        now |= 1 << x[i].second;
        if (f[a][now]) {
          printf("%d\n", x[i].first);
          break;
        }
      }
    }
  }
}
