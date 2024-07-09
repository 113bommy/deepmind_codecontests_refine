#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int p[2503];
vector<pair<int, int> > a[102];
int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
void mer(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return;
  if (p[x] > p[y]) swap(x, y);
  p[x] += p[y];
  p[y] = x;
}
int main() {
  ios::sync_with_stdio(false);
  mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
  int n, z = 0, e[52] = {}, f[52] = {};
  string s[52] = {};
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  clock_t cl = clock();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == '#') z++, e[i] = 1, f[j] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == '#') {
        for (int k = 0; k < n; k++)
          for (int l = 0; l < n; l++)
            if (s[k][l] == '#') {
              if (i != k || j != l) {
                a[abs(i - k) + abs(j - l)].push_back({i * n + j, k * n + l});
              }
            }
      }
  int g = 0, h = 0;
  for (int i = 0; i < n; i++) g += e[i], h += f[i];
  if (g == n || h == n) {
    cout << n;
    return 0;
  }
  while (clock() - cl < 700) {
    for (int i = 0; i < n * n; i++) p[i] = -1;
    for (int i = 0; i < n + n; i++) shuffle(a[i].begin(), a[i].end(), rng);
    for (int i = 0; i < n + n; i++) {
      for (pair<int, int> j : a[i])
        if (root(j.first) != root(j.second)) {
          mer(j.first, j.second);
          int u[2503] = {}, v[2503] = {}, w[2503] = {}, x[2503] = {}, t = 0;
          for (int k = 0; k < n * n; k++) u[k] = w[k] = 328;
          for (int k = 0; k < n; k++)
            for (int l = 0; l < n; l++)
              if (s[k][l] == '#') {
                int y = root(k * n + l);
                u[y] = min(u[y], k);
                v[y] = max(v[y], k);
                w[y] = min(w[y], l);
                x[y] = max(x[y], l);
              }
          for (int k = 0; k < n * n; k++)
            if (u[k] != 328) {
              t += max(v[k] - u[k] + 1, x[k] - w[k] + 1);
            }
          z = min(z, t);
        }
    }
  }
  cout << z;
}
